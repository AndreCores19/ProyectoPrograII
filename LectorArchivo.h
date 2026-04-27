
#ifndef PROYECTOPROGRAII_LECTORARCHIVO_H
#define PROYECTOPROGRAII_LECTORARCHIVO_H
#include "Laboratorio.h"
#include "Computador.h"
#include "Servidor.h"
#include "Incidencia.h"
#include "ArchivoInvalido.h"
#include "FormatoInvalido.h"
#include "OperacionInconsistente.h"
#include <fstream>
#include <sstream>
using namespace std;

class LectorArchivo {
    string rutaEquipos;
    string rutaIncidencias;
public:
    LectorArchivo(string rutaEquipos, string rutaIncidencias);
    ~LectorArchivo() = default;
    void cargarEquipos(Laboratorio* laboratorio);
    void cargarIncidencias(Laboratorio* laboratorio);
};


#endif //PROYECTOPROGRAII_LECTORARCHIVO_H