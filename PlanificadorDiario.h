
#ifndef PROYECTOPROGRAII_PLANIFICADORDIARIO_H
#define PROYECTOPROGRAII_PLANIFICADORDIARIO_H
#include "Ordenamiento.h"
using namespace std;
class Laboratorio;

class PlanificadorDiario {
    Ordenamiento ordenamiento;
    Laboratorio* laboratorio;
    int maxEqPorDia;
    void atenderEquipos(Equipo**, int);
public:
    PlanificadorDiario(Laboratorio*);
    void planificarDía(Equipo**, int);
};


#endif //PROYECTOPROGRAII_PLANIFICADORDIARIO_H