//
// Created by andre on 22/4/2026.
//

#ifndef PROYECTOPROGRAII_COMPUTADOR_H
#define PROYECTOPROGRAII_COMPUTADOR_H
#include "Equipo.h"

class Computador : public Equipo
{
private:
    float nivelDegradacion;
public:
    Computador(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas, float nivelDegradacion);
    Computador();
    ~Computador() override;
    void setNivelDegradacion(float);
    float getNivelDegradacion();
    float calcularPrioridad() override;
    void aplicaDegradacion() override;
    void aplicaMantenimiento() override;
};


#endif //PROYECTOPROGRAII_COMPUTADOR_H