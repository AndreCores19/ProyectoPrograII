//
// Created by andre on 22/4/2026.
//

#ifndef PROYECTOPROGRAII_COMPUTADOR_H
#define PROYECTOPROGRAII_COMPUTADOR_H
#include "Equipo.h"
using namespace std;

class Computador : public Equipo {
    float nivelDegradacion;
public:
    Computador();
    ~Computador() override;
    float calcularPrioridad() override;
    void Degradacion() override;
    void aplicaMantenimiento() override;
    string getId() const override;
};


#endif //PROYECTOPROGRAII_COMPUTADOR_H