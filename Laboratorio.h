
#ifndef PROYECTOPROGRAII_LABORATORIO_H
#define PROYECTOPROGRAII_LABORATORIO_H
#include "Equipo.h"

class Laboratorio {
protected:
    Equipo** equipos;
    int cantidad;
    int tamano;
    int diaActual;
public:
    Laboratorio();
    Laboratorio(Equipo**, int, int, int, float);
    virtual ~Laboratorio();
    void setDiaActual(int);
    int getDiaActual();
    void generarIncidencias();
    void degradarEquipos();
    void calcularRiesgoActual();
    void agregarEquipo(Equipo*);
};


#endif //PROYECTOPROGRAII_LABORATORIO_H