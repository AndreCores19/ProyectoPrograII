
#include "Laboratorio.h"
//hola
Laboratorio::Laboratorio() {
    this->tamano = 100;
    this->cantidad = 0;
    this->diaActual = 0;
    this->equipos = new Equipo*[tamano];
    for (int i = 0; i < tamano; i++) {
        equipos[i] = nullptr;
    }
}

Laboratorio::Laboratorio(Equipo** equipos, int cantidad, int tamano, int diaActual) {
        this->tamano = tamano;
        this->cantidad = cantidad;
        this->diaActual = diaActual;
        this->equipos = new Equipo*[tamano];
        for (int i = 0; i < cantidad; i++) {
            this->equipos[i] = equipos[i];
        }
}

Laboratorio::~Laboratorio() {
    if (equipos != nullptr) {
        for (int i = 0; i < cantidad; i++) {
            delete equipos[i];
        }
        delete[] equipos;
    }
}

void Laboratorio::setDiaActual(int diaActual) {
    this->diaActual = diaActual;
}

int Laboratorio::getDiaActual() {
    return this->diaActual;
}

void Laboratorio::degradarEquipos() {
    for (int i = 0; i < cantidad; i++) {
        if (equipos[i] != nullptr) {
            equipos[i]->aplicaDegradacion();
        }
    }
}

float Laboratorio::calcularRiesgoActual() {
    float riesgoTotal = 0.0;
    for (int i = 0; i < cantidad; i++) {
        if (equipos[i] != nullptr) {
            riesgoTotal += equipos[i]->calcularPrioridad();
        }
    }
    return riesgoTotal / cantidad;
}

void Laboratorio::agregarEquipo(Equipo* nuevo) {
    if (cantidad < tamano) {
        for (int i = 0; i < tamano; i++) {
            if (equipos[i] == nullptr) {
                equipos[i] = nuevo;
                cantidad++;
                break;
            }
        }
    }
}
