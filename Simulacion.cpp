
#include "Simulacion.h"

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

}
