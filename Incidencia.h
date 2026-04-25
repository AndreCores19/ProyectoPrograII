#ifndef PROYECTOPROGRAII_INCIDENCIA_H
#define PROYECTOPROGRAII_INCIDENCIA_H
#include "Equipo.h"
//Severidad declarada
const int Baja = 0;
const int Media = 1;
const int Alta = 2;

class Incidencia {
private:
    Equipo *idEquipo;
    int severidad;
    int diaRegistro;
    bool fallaAtendida;
public:
    Incidencia();
    Incidencia(Equipo* idEquipo, int, int);
    ~Incidencia();
    string getIdEquipo();
    int getSeveridad() const;
    void resolver();
};


#endif //PROYECTOPROGRAII_INCIDENCIA_H