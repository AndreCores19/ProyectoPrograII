
#include "Equipo.h"

#include "OperacionInconsistente.h"

Equipo::Equipo(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas){
    this->id = id;
    this->estado = estado;
    this->tiempoInactivo = tiempoInactivo;
    this->criticidad = criticidad;
    this->incidenciasActivas = incidenciasActivas;
    incidencias = new Incidencia*[maxIncidencias];
    for (int i = 0; i < maxIncidencias; i++) {
        incidencias[i] = nullptr;
    }
}

Equipo::Equipo(){
     id = "Por defecto";
     estado = 100;
     tiempoInactivo = 0;
     criticidad = 1;
     incidenciasActivas = 0;
    incidencias = new Incidencia*[maxIncidencias];
    for (int i = 0; i < maxIncidencias; i++) {
        incidencias[i] = nullptr;
    }
}

void Equipo::setId(string id) {
    this->id = id;
}
string Equipo::getId() {
    return id;
}
void Equipo::setEstado(float estado) {
    this->estado = estado;
}
float Equipo::getEstado() {
    return estado;
}
void Equipo::setTiempoInactivo(int tiempoInactivo) {
    this->tiempoInactivo = tiempoInactivo;
}
int Equipo::getTiempoInactivo() {
    return tiempoInactivo;
}
void Equipo::setCriticidad(int criticidad) {
    this->criticidad = criticidad;
}
int Equipo::getCriticidad() {
    return criticidad;
}

void Equipo::setIncidenciasActiva(int incidenciasActivas) {
    this->incidenciasActivas = incidenciasActivas;
}

int Equipo::getIncidenciasActiva() {
    return incidenciasActivas;
}
Equipo::~Equipo() {
    for (int i = 0; i < incidenciasActivas; i++) {
        if (incidencias[i] != nullptr)
            delete incidencias[i];
    }
    delete[] incidencias;
}

void Equipo::agregarIncidencia(Incidencia* inc) {
    // Validar que no se supere el máximo
    if (incidenciasActivas >= maxIncidencias)
        throw OperacionInconsistente("Equipo " + id + " alcanzó el máximo de incidencias");

    incidencias[incidenciasActivas] = inc;
    incidenciasActivas++;
}
