#ifndef PROYECTOPROGRAII_SERVIDOR_H
#define PROYECTOPROGRAII_SERVIDOR_H
#include "Equipo.h"
class Servidor : public Equipo {
    float nivelDegradacion;
public:
    Servidor(string, float, int, int, int, float);
    Servidor();
    ~Servidor() override;
    void setNivelDegradacion(float);
    float getNivelDegradacion();
    float calcularPrioridad() override;
    void aplicaDegradacion() override;
    void aplicaMantenimiento() override;
    string getId() const override;
};

#endif //PROYECTOPROGRAII_SERVIDOR_H