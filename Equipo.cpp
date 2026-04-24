
#include "Equipo.h"

Equipo::Equipo(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas){
    this->id = id;
    this->estado = estado;
    this->tiempoInactivo = tiempoInactivo;
    this->criticidad = criticidad;
    this->incidenciasActivas = incidenciasActivas;
}

Equipo::Equipo(){
     id = "Por defecto";
     estado = 100;
     tiempoInactivo = 0;
     criticidad = 1;
     incidenciasActivas = 0;
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
Equipo::~Equipo(){}
