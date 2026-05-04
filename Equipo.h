
#ifndef PROYECTOPROGRAII_EQUIPO_H
#define PROYECTOPROGRAII_EQUIPO_H
#include <iostream>
#include <sstream>
#include "Incidencia.h"
using namespace std;

const int maxIncidencias = 100;

class Equipo {
protected:
    string id;
    float estado;
    int tiempoInactivo;
    int criticidad;
    int incidenciasActivas;
    Incidencia** incidencias;
public:
    Equipo();
    Equipo(string, float, int, int, int);
    virtual ~Equipo() = 0;
    void setId(string);
    string getId();
    void setEstado(float);
    float getEstado();
    void setTiempoInactivo(int);
    int getTiempoInactivo();
    void setCriticidad(int);
    int getCriticidad();
    void setIncidenciasActiva(int);
    int getIncidenciasActiva();
    void aplicaDegradacion();
    void aplicaMantenimiento();
    virtual float calcularDesgaste() = 0;
    virtual float calcularRecuperacion() = 0;
    virtual float calcularPrioridad() = 0;
    virtual string getId() const = 0;
    void agregarIncidencia(Incidencia*);
    virtual string toString();
    string toStringIncidencias();

};

#endif //PROYECTOPROGRAII_EQUIPO_H