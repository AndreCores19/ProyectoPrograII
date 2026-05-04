#ifndef PROYECTOPROGRAII_SERVIDOR_H
#define PROYECTOPROGRAII_SERVIDOR_H
#include "Equipo.h"
class Servidor : public Equipo {
private:
    float nivelDegradacion;
public:
    Servidor(string, float, int, int, int, float);
    Servidor();
    ~Servidor() override;
    void setNivelDegradacion(float);
    float getNivelDegradacion();
    float calcularDesgaste() override;
    float calcularRecuperacion() override;
    float calcularPrioridad() override;
    string getId() const override;
    string toString() override;
};

#endif //PROYECTOPROGRAII_SERVIDOR_H