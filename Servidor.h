//
// Created by julia on 23/4/2026.
//

#ifndef PROYECTOPROGRAII_SERVIDOR_H
#define PROYECTOPROGRAII_SERVIDOR_H
#include "Equipo.h"
class Servidor : public Equipo {
private:
    float nivelDegradacion;
public:
    Servidor(string id, float estado, int tiempoInactivo, int criticidad, int incidenciasActivas, float nivelDegradacion);
    Servidor();
    ~Servidor() override;
    void setNivelDegradacion(float);
    float getNivelDegradacion();
    float calcularPrioridad() override;
    void aplicaDegradacion() override;
    void aplicaMantenimiento() override;
};

#endif //PROYECTOPROGRAII_SERVIDOR_H