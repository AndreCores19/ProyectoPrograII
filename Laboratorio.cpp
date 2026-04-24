//
// Created by julia on 23/4/2026.
//

#include "Laboratorio.h"

Laboratorio::Laboratorio() {
    this->tamano = 100;
    this->cantidad = 0;
    this->diaActual = 0;
    this->riesgoActual = 0.0;
    this->equipos = new Equipo*[tamano];
    for (int i = 0; i < tamano; i++) {
        equipos[i] = nullptr;
    }
}

Laboratorio::Laboratorio(Equipo** equipos, int cantidad, int tamano, int diaActual, float riesgoActual) {
        this->tamano = tamano;
        this->cantidad = cantidad;
        this->diaActual = diaActual;
        this->riesgoActual = riesgoActual;
        this->equipos = new Equipo*[tamano];
        for (int i = 0; i < cantidad; i++) {
            equipos[i] = equipos[i];
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

void Laboratorio::setRiesgoActual(float riesgoActual) {
    this->riesgoActual = riesgoActual;
}

float Laboratorio::getRiesgoActual() {
    return this->riesgoActual;
}

void Laboratorio::ejecutarSimulacion() {
}

void Laboratorio::degradarEquipos() {
}

float Laboratorio::calcularRiesgoActual() {
}

void Laboratorio::agregarEquipo() {
}
