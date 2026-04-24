//
// Created by julia on 23/4/2026.
//

#ifndef PROYECTOPROGRAII_LABORATORIO_H
#define PROYECTOPROGRAII_LABORATORIO_H
#include "Equipo.h"

class Laboratorio {
protected:
    Equipo** equipos;
    int cantidad;
    int tamano;
    int diaActual;
    float riesgoActual;
public:
    Laboratorio();
    Laboratorio(Equipo** equipos, int cantidad, int tamano, int diaActual, float riesgoActual);
    virtual ~Laboratorio();
    void setDiaActual(int diaActual);
    int getDiaActual();
    void setRiesgoActual(float riesgoActual);
    float getRiesgoActual();
    void ejecutarSimulacion();
    void degradarEquipos();
    float calcularRiesgoActual();
    void agregarEquipo();
};


#endif //PROYECTOPROGRAII_LABORATORIO_H