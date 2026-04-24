
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
    Laboratorio(Equipo**, int, int, int, float);
    virtual ~Laboratorio();
    void setDiaActual(int);
    int getDiaActual();
    void setRiesgoActual(float);
    float getRiesgoActual();
    void ejecutarSimulacion();
    void degradarEquipos();
    float calcularRiesgoActual();
    void agregarEquipo();
};


#endif //PROYECTOPROGRAII_LABORATORIO_H