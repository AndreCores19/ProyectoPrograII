#include "Servidor.h"

Servidor::Servidor(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas, float nivelDegradacion)
    : Equipo(id, estado, tiempoInactivo, criticidad, incidenciasActivas) {
    this->nivelDegradacion = nivelDegradacion;
}

Servidor::Servidor() : Equipo() {
    nivelDegradacion = 0.0;
}

Servidor::~Servidor() {}

void Servidor::setNivelDegradacion(float nivelDegradacion) {
    this->nivelDegradacion = nivelDegradacion;
}

float Servidor::getNivelDegradacion() {
    return nivelDegradacion;
}

float Servidor::calcularPrioridad() {
    return (criticidad * 0.5) + (incidenciasActivas * 0.3) + (tiempoInactivo * 0.2);
}

float Servidor::calcularDesgaste() {
    return 8 * nivelDegradacion;
}

float Servidor::calcularRecuperacion() {
    return 30.0;
}

string Servidor::getId() const {
    return id;
}

string Servidor::toString() {
    stringstream ss;
    ss << Equipo::toString();
    ss << nivelDegradacion << endl;
    return ss.str();
}
