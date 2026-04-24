//
// Created by julia on 23/4/2026.
//

#include "Servidor.h"

Servidor::Servidor(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas, float nivelDegradacion)
    : Equipo(id, estado, tiempoInactivo, criticidad, incidenciasActivas) {
    this->nivelDegradacion = nivelDegradacion;
}
Servidor::Servidor() : Equipo() {
    nivelDegradacion = 0.0;
}
Servidor::~Servidor(){}

void Servidor::setNivelDegradacion(float nivelDegradacion) {
    this->nivelDegradacion = nivelDegradacion;
}

float Servidor::getNivelDegradacion() {
    return nivelDegradacion;
}

float Servidor::calcularPrioridad() {
    return (criticidad * 0.5) + (incidenciasActivas * 0.3) + (tiempoInactivo * 0.2);
}

void Servidor::aplicaDegradacion() {
    estado -= 5 * nivelDegradacion;
    tiempoInactivo += 1;
    if (estado < 0) {
        estado = 0;
    }
}
void Servidor::aplicaMantenimiento() {
    estado += 20;
    tiempoInactivo = 0;
    if (incidenciasActivas > 0) {
        incidenciasActivas--;
    }
    if (estado > 100) {
        estado = 100;
    }
}