//
// Created by andre on 24/4/2026.
//

#ifndef PROYECTOPROGRAII_ORDENAMIENTO_H
#define PROYECTOPROGRAII_ORDENAMIENTO_H
#include <iostream>
#include "Equipo.h"
using namespace std;

class Ordenamiento {
    void mergeSort(Equipo**, int, int);
    void merge(Equipo**, int, int, int);
public:
    void ordenar(Equipo**, int);
    Ordenamiento();

};


#endif //PROYECTOPROGRAII_ORDENAMIENTO_H