
#ifndef PROYECTOPROGRAII_COMPUTADOR_H
#define PROYECTOPROGRAII_COMPUTADOR_H
#include "Equipo.h"

class Computador : public Equipo {
private:
    float nivelDegradacion;
public:
    Computador(string, float, int, int, int, float);
    Computador();
    ~Computador() override;
    void setNivelDegradacion(float);
    float getNivelDegradacion();
    float calcularDesgaste() override;
    float calcularRecuperacion() override;
    float calcularPrioridad() override;
    string getId() const override;
    string toString() override;
};


#endif //PROYECTOPROGRAII_COMPUTADOR_H