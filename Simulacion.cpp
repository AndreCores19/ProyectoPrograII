
#include "Simulacion.h"

void Simulacion::ejecutarDia(int diaActual) {
    laboratorio->degradarEquipos();
    planificador->planificarDía(laboratorio->getEquipos(), laboratorio->getCantidad());
    laboratorio->setDiaActual(diaActual);
    reporte->genReporteDiario(laboratorio->getEquipos(), laboratorio->getCantidad());
}

Simulacion::Simulacion(string rutaEquipos, string rutaIncidencias) {
    totalDias = 30;
    laboratorio = new Laboratorio();
    planificador = new PlanificadorDiario(laboratorio);
    lector = new LectorArchivo(rutaEquipos, rutaIncidencias);
    reporte = new GenerarReporte(laboratorio);
    lector->cargarEquipos(laboratorio);
    lector->cargarIncidencias(laboratorio);
}

Simulacion::~Simulacion() {
    delete laboratorio;
    delete planificador;
    delete lector;
    delete reporte;
}



void Simulacion::ejecutarSimulacion() {
    cout << "Ejecutando simulacion..." << endl;
    for (int i = 0; i < totalDias; i++) {

    }
}
