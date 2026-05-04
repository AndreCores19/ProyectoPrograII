#include "LectorArchivo.h"

LectorArchivo::LectorArchivo(string rutaEquipos, string rutaIncidencias) {
    this->rutaEquipos = rutaEquipos;
    this->rutaIncidencias = rutaIncidencias;
}

LectorArchivo::LectorArchivo(){
    rutaEquipos = " ";
    rutaIncidencias = " ";
}

void LectorArchivo::cargarEquipos(Laboratorio* laboratorio) {
    ifstream archivo(rutaEquipos);
    if (!archivo.is_open()) {
        throw ArchivoInvalido("No se pudo abrir: " + rutaEquipos);
    }

    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea)) { //lee una línea del archivo y la guarda en linea
        bool soloEspacios = true;
        for (int i = 0; i < linea.size(); i++) {
            if (linea[i] != ' ' && linea[i] != '\t' && linea[i] != '\r') {
                soloEspacios = false;
                break;
            }
        }
        if (linea.empty() || soloEspacios) continue;  // saltar esta línea
        stringstream ss(linea);
        string id, tipo, estadoStr, tiempoStr, criticidadStr, incidenciasStr, degradacionStr;
        // Extrae cada campo hasta encontrar un ';'
        getline(ss, id, ';');
        getline(ss, tipo, ';');
        getline(ss, estadoStr, ';');
        getline(ss, tiempoStr, ';');
        getline(ss, criticidadStr, ';');
        getline(ss, incidenciasStr, ';');
        getline(ss, degradacionStr);

        if (id.empty() || tipo.empty()) {
            throw FormatoInvalido("Linea mal hecha: " + linea);
        }

        auto limpiar = [](string s) {
            s.erase(0, s.find_first_not_of(" \t\r\n"));
            s.erase(s.find_last_not_of(" \t\r\n") + 1);
            return s;
        };
        //// Convierte los strings a los tipos correctos
        float estado = stof(limpiar(estadoStr));
        int tiempoInactivo = stoi(limpiar(tiempoStr));
        int criticidad = stoi(limpiar(criticidadStr));
        int incidencias = stoi(limpiar(incidenciasStr));
        float degradacion = stof(limpiar(degradacionStr));

        if (tipo == "Computador") {
            laboratorio->agregarEquipo(new Computador(id, estado, tiempoInactivo, criticidad, incidencias, degradacion));
        } else if (tipo == "Servidor") {
            laboratorio->agregarEquipo(new Servidor(id, estado, tiempoInactivo, criticidad, incidencias, degradacion));
        } else {
            throw FormatoInvalido("Equipo desconocido: " + tipo);
        }
    }
    archivo.close();
}

void LectorArchivo::cargarIncidencias(Laboratorio* laboratorio) {
    ifstream archivo(rutaIncidencias);
    if (!archivo.is_open())
        throw ArchivoInvalido("No se pudo abrir: " + rutaIncidencias);

    string linea;
    getline(archivo, linea); // saltar encabezado

    while (getline(archivo, linea)) {
        bool soloEspacios = true;
        for (int i = 0; i < linea.size(); i++) {
            if (linea[i] != ' ' && linea[i] != '\t' && linea[i] != '\r') {
                soloEspacios = false;
                break;
            }
        }
        if (linea.empty() || soloEspacios) continue;  // saltar esta línea
        stringstream ss(linea);
        string idEquipo, severidadStr, diaStr;
        getline(ss, idEquipo, ';');
        getline(ss, severidadStr, ';');
        getline(ss, diaStr, ';');

        if (idEquipo.empty())
            throw FormatoInvalido("Linea mal hecha: " + linea);

        int severidad = stoi(severidadStr);
        int dia = stoi(diaStr);

        if (severidad < 0 || severidad > 2)
            throw OperacionInconsistente("Severidad invalida: " + severidadStr);

        Equipo* equipo = laboratorio->buscarEquipo(idEquipo);
        if (equipo == nullptr)
            throw OperacionInconsistente("Equipo no encontrado: " + idEquipo);

        equipo->agregarIncidencia(new Incidencia(idEquipo, severidad, dia));
    }

    archivo.close();
}

void LectorArchivo::setRutaEquipos(string rutaEquipos) {
    this->rutaEquipos = rutaEquipos;
}

void LectorArchivo::setRutaIncidencias(string rutaIncidencias) {
    this->rutaIncidencias = rutaIncidencias;
}
