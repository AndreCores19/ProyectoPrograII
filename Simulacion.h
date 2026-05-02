
#ifndef PROYECTOPROGRAII_SIMULACION_H
#define PROYECTOPROGRAII_SIMULACION_H
#include "Laboratorio.h"
#include "PlanificadorDiario.h"
#include "LectorArchivo.h"
#include "GenerarReporte.h"
using namespace std;

class Simulacion {
    Laboratorio* laboratorio;
    PlanificadorDiario* planificador;
    LectorArchivo* lector;
    GenerarReporte* reporte;
    int totalDias;

    void ejecutarDia(int diaActual);
public:
    Simulacion(string, string);
    ~Simulacion();
    void ejecutarSimulacion();
};


#endif //PROYECTOPROGRAII_SIMULACION_H