
#include "GenerarReporte.h"




GenerarReporte::GenerarReporte(Laboratorio* laboratorio) {
    this->laboratorio = laboratorio;
    reporte.open("reporte.txt");
}

GenerarReporte::~GenerarReporte() {
    if (reporte.is_open()) {
        reporte.close();
    }
}
string GenerarReporte::clasificarRiesgo(float riesgo) {
    if (riesgo >= 7.0) return "ALTO";
    if (riesgo >= 4.0) return "MEDIO";
    return "BAJO";
}

void GenerarReporte::genReporteDiario(Equipo** atendidos, int numAtendidos) {
    reporte << "========== DIA " << laboratorio->getDiaActual() << " ==========" << endl;

    // Equipos atendidos con su prioridad
    reporte << "Equipos atendidos:" << endl;
    for (int i = 0; i < numAtendidos; i++) {
        reporte << "  ID: " << atendidos[i]->getId()
                << " | Prioridad: " << atendidos[i]->calcularPrioridad()
                << " | Estado: " << atendidos[i]->getEstado() << endl
                << endl;
    }

    float riesgo = laboratorio->calcularRiesgoActual();
    reporte << "Riesgo global: " << clasificarRiesgo(riesgo) << endl << endl;

    // Equipos pendientes
    int pendientes = laboratorio->getCantidad() - numAtendidos;
    reporte << "Equipos pendientes: " << pendientes << endl;
    reporte << "========================================" << endl << endl;
}