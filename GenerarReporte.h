
#ifndef PROYECTOPROGRAII_GENERARREPORTE_H
#define PROYECTOPROGRAII_GENERARREPORTE_H
#include "Laboratorio.h"
#include "ArchivoInvalido.h"
#include <fstream>
using namespace std;

class GenerarReporte {
    ofstream reporte;
    Laboratorio *laboratorio;
public:
    GenerarReporte(Laboratorio*);
    ~GenerarReporte();
    string clasificarRiesgo(float riesgo);
    void genReporteDiario(Equipo**, int);
    void genReporteFinal();
};


#endif //PROYECTOPROGRAII_GENERARREPORTE_H