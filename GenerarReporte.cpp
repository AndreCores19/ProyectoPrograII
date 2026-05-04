
#include "GenerarReporte.h"

GenerarReporte::GenerarReporte(Laboratorio* laboratorio) {
    this->laboratorio = laboratorio;
}

GenerarReporte::~GenerarReporte() {}

string GenerarReporte::clasificarRiesgo(float riesgo) {
    if (riesgo >= 7.0) return "ALTO";
    if (riesgo >= 4.0) return "MEDIO";
    return "BAJO";
}

void GenerarReporte::genReporteDiario() {
    int dia = laboratorio->getDiaActual();
    string nombreArchivo = "reporte_dia_" + to_string(dia) + ".txt";

    ofstream archivo(nombreArchivo);
    if (!archivo.is_open())
        throw ArchivoInvalido("No se pudo crear: " + nombreArchivo);

    float riesgo = laboratorio->calcularRiesgoActual();
    Equipo** equipos = laboratorio->getEquipos();
    int cantidad = laboratorio->getCantidad();
    archivo << "========== DIA #" << dia << " ==========" << endl;
    archivo << "Riesgo global: " << clasificarRiesgo(riesgo) << endl << endl;

    int atendidos = (cantidad >= 3) ? 3 : cantidad;
    archivo << "--- Equipos atendidos ---" << endl;
    for (int i = 0; i < atendidos; i++) {
        if (equipos[i] != nullptr)
            archivo << "  ID: " << equipos[i]->getId()
                    << " | Prioridad: " << equipos[i]->calcularPrioridad()
                    << " | Estado: " << equipos[i]->getEstado()
                    << " | Incidencias: " << equipos[i]->getIncidenciasActiva()
                    << endl;
    }

    archivo << endl << "--- Equipos pendientes (" << (cantidad - atendidos) << ") ---" << endl;
    for (int i = atendidos; i < cantidad; i++) {
        if (equipos[i] != nullptr)
            archivo << "  ID: " << equipos[i]->getId()
                    << " | Prioridad: " << equipos[i]->calcularPrioridad()
                    << " | Estado: " << equipos[i]->getEstado()
                    << endl;
    }

    archivo << "==========================================" << endl;
    archivo.close();
}

void GenerarReporte::genReporteFinal() {
    string nombreArchivo = "reporte_final.txt";

    ofstream archivo(nombreArchivo);
    if (!archivo.is_open())
        throw ArchivoInvalido("No se pudo crear: " + nombreArchivo);

    Equipo** equipos = laboratorio->getEquipos();
    int cantidad = laboratorio->getCantidad();
    float riesgoFinal = laboratorio->calcularRiesgoActual();

    archivo << "================== RESUMEN FINAL ====================" << endl;
    archivo << "Total de dias simulados: " << laboratorio->getDiaActual() << endl;
    archivo << "Total de equipos: " << cantidad << endl;
    archivo << "Riesgo final: " << clasificarRiesgo(riesgoFinal) << " (" << riesgoFinal << ")" << endl << endl;

    archivo << "Estado final de equipos:" << endl << endl;

    for (int i = 0; i < cantidad; i++) {
        if (equipos[i] != nullptr) {
            archivo << equipos[i]->toString() << endl;

            Servidor* srv = dynamic_cast<Servidor*>(equipos[i]);
            if (srv != nullptr) {
                archivo << "  Tipo: Servidor" << endl;
                archivo << "  Nivel de degradacion: " << srv->getNivelDegradacion() << endl;
            }

            Computador* comp = dynamic_cast<Computador*>(equipos[i]);
            if (comp != nullptr) {
                archivo << "  Tipo: Computador" << endl;
                archivo << "  Nivel de degradacion: " << comp->getNivelDegradacion() << endl;
            }

            archivo << endl;
        }
    }

    archivo << "======================================================" << endl;
    archivo.close();
}

void GenerarReporte::mostrarReporteDia(int dia) {
    string nombreArchivo = "reporte_dia_" + to_string(dia) + ".txt";

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No existe reporte para el dia " << dia << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)){
        cout << linea << endl;
    }
    archivo.close();
}

void GenerarReporte::mostrarReporteFinal() {
    string nombreArchivo = "reporte_final.txt";
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No existe reporte final." << endl;;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}




