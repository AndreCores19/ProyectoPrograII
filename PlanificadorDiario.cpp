
#include "PlanificadorDiario.h"
#include "Laboratorio.h"

void PlanificadorDiario::atenderEquipos(Equipo** equipos, int cantidad) {
    int atender = 0;
    if (cantidad >= maxEqPorDia) {
        atender = maxEqPorDia;
    }else {
        atender = cantidad;
    }
    for (int i = 0; i < atender; i++) {
        equipos[i]->aplicaMantenimiento();
    }
}

PlanificadorDiario::PlanificadorDiario(Laboratorio* labo) {
    laboratorio = labo;
    maxEqPorDia = 3;
}

void PlanificadorDiario::planificarDia(Equipo** equipos, int cantidad) {
    ordenamiento.ordenar(equipos, cantidad);
    atenderEquipos(equipos, cantidad);
}
