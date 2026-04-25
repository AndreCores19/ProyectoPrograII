#include "Incidencia.h"

Incidencia::Incidencia() {
    idEquipo = nullptr;
    severidad = Baja;
    diaRegistro = 0;
    fallaAtendida = false;
}
Incidencia::Incidencia(Equipo* idEquipo, int severidad, int diaRegistro) {
    this->idEquipo = idEquipo;
    this->severidad = severidad;
    this->diaRegistro = diaRegistro;
    this->fallaAtendida = false;
}
Incidencia::~Incidencia() {}

string Incidencia::getIdEquipo() {
    return idEquipo->getId();
}

int Incidencia::getSeveridad() const {
    return severidad;
}
void Incidencia::resolver() {
    fallaAtendida = true;
}
