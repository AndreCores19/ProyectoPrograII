//
// Created by andre on 15/4/2026.
//

#ifndef PROYECTOPROGRAII_EQUIPO_H
#define PROYECTOPROGRAII_EQUIPO_H
#include <iostream>
using namespace std;

class Equipo {
    string id;
    float estado;
    int tiempoInactivo;
    int criticidad;
    int incidenciasActivas;

public:
    Equipo();
    virtual ~Equipo() = 0;
    virtual float calcularPrioridad() = 0;
    virtual void Degradacion() = 0;
    virtual void aplicaMantenimiento() = 0;
    virtual string getId() const = 0;

};


#endif //PROYECTOPROGRAII_EQUIPO_H