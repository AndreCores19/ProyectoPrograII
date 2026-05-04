#include "Computador.h"

Computador::Computador(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas, float nivelDegradacion)
    : Equipo(id, estado, tiempoInactivo, criticidad, incidenciasActivas) {
    this->nivelDegradacion = nivelDegradacion;
}

Computador::Computador() : Equipo() {
    nivelDegradacion = 0.0;
}

Computador::~Computador() {}

void Computador::setNivelDegradacion(float nivelDegradacion) {
    this->nivelDegradacion = nivelDegradacion;
}

float Computador::getNivelDegradacion() {
    return nivelDegradacion;
}

float Computador::calcularPrioridad() {
    return (criticidad * 0.5) + (incidenciasActivas * 0.3) + (tiempoInactivo * 0.2);
}

float Computador::calcularDesgaste() {
    return 5 * nivelDegradacion;
}

float Computador::calcularRecuperacion() {
    return 20.0;
}

string Computador::getId() const {
    return id;
}

string Computador::toString() {
    stringstream ss;
    ss << Equipo::toString();
    ss << nivelDegradacion << endl;
    return ss.str();
}
