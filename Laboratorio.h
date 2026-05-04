
#ifndef PROYECTOPROGRAII_LABORATORIO_H
#define PROYECTOPROGRAII_LABORATORIO_H
#include "Equipo.h"
#include <cstdlib>
#include <ctime>
class Laboratorio {
protected:
    Equipo** equipos;
    int cantidad;
    int tamano;
    int diaActual;
public:
    Laboratorio();
    Laboratorio(Equipo**, int, int, int);
    virtual ~Laboratorio();
    void setDiaActual(int);
    int getDiaActual();
    void degradarEquipos();
    float calcularRiesgoActual();
    void agregarEquipo(Equipo*);
    Equipo* buscarEquipo(string id);
    int getCantidad();
    Equipo** getEquipos();
    void generarIncidenciasAleatorias(int totalIncidencias);
};


#endif //PROYECTOPROGRAII_LABORATORIO_H