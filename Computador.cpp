
#include "Computador.h"

Computador::Computador(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas, float nivelDegradacion)
    : Equipo(id, estado, tiempoInactivo, criticidad, incidenciasActivas) {
    this->nivelDegradacion = nivelDegradacion;
}
Computador::Computador(){
    nivelDegradacion = 0.0;
}
Computador::~Computador(){}

void Computador::setNivelDegradacion(float nivelDegradacion) {
    this->nivelDegradacion = nivelDegradacion;
}

float Computador::getNivelDegradacion() {
    return nivelDegradacion;
}

float Computador::calcularPrioridad() {
    return (criticidad * 0.5) + (incidenciasActivas * 0.3) + (tiempoInactivo * 0.2);
}

void Computador::aplicaDegradacion() {
    estado -= 5 * nivelDegradacion;
    tiempoInactivo += 1;
    if (estado < 0) {
        estado = 0;
    }
}
void Computador::aplicaMantenimiento() {
    estado += 20;
    tiempoInactivo = 0;
    if (incidenciasActivas > 0) {
        incidencias[incidenciasActivas - 1]->resolver();
        incidenciasActivas--;
    }
    if (estado > 100) {
        estado = 100;
    }
}

string Computador::getId() const{
    return id;
}

