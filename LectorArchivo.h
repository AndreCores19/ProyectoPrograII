
#ifndef PROYECTOPROGRAII_LECTORARCHIVO_H
#define PROYECTOPROGRAII_LECTORARCHIVO_H
#include "Laboratorio.h"
#include "Computador.h"
#include "Servidor.h"
#include <iostream>
using namespace std;

class LectorArchivo : public Laboratorio{
    string rutaArchivo;
public:
    LectorArchivo(string);
    Equipo** cargarEquipos() override;
    Equipo** cargarIncidencias() override;
    ~LectorArchivo() = default;

};


#endif //PROYECTOPROGRAII_LECTORARCHIVO_H