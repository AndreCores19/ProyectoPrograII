
#ifndef PROYECTOPROGRAII_LECTORARCHIVO_H
#define PROYECTOPROGRAII_LECTORARCHIVO_H
#include "Laboratorio.h"
#include <iostream>
using namespace std;

class LectorArchivo : public Laboratorio{
    string rutaArchivo;
public:
    LectorArchivo(string);
    void cargarEquipos(int); //CAMBIAR A Equipo**
    void cargarIncidencias();
    ~LectorArchivo();

};


#endif //PROYECTOPROGRAII_LECTORARCHIVO_H