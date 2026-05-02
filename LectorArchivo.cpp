#include "LectorArchivo.h"

LectorArchivo::LectorArchivo(string rutaEquipos, string rutaIncidencias) {
    this->rutaEquipos = rutaEquipos;
    this->rutaIncidencias = rutaIncidencias;
}

void LectorArchivo::cargarEquipos(Laboratorio* laboratorio) {
    ifstream archivo(rutaEquipos);
    if (!archivo.is_open()) {
        throw ArchivoInvalido("No se pudo abrir: " + rutaEquipos);
    }

    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea)) { //lee una línea del archivo y la guarda en linea
        stringstream ss(linea);
        string id, tipo, estadoStr, tiempoStr, criticidadStr, incidenciasStr, degradacionStr;
        // Extrae cada campo hasta encontrar un ';'
        getline(ss, id, ';');
        getline(ss, tipo, ';');
        getline(ss, estadoStr, ';');
        getline(ss, tiempoStr, ';');
        getline(ss, criticidadStr, ';');
        getline(ss, incidenciasStr, ';');
        getline(ss, degradacionStr, ';');

        if (id.empty() || tipo.empty()) {
            throw FormatoInvalido("Linea mal hecha: " + linea);
        }
        //// Convierte los strings a los tipos correctos
        float estado = stof(estadoStr);
        int tiempoInactivo = stoi(tiempoStr);
        int criticidad = stoi(criticidadStr);
        int incidencias = stoi(incidenciasStr);
        float degradacion = stof(degradacionStr);

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