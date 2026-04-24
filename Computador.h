
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
    float calcularPrioridad() override;
    void aplicaDegradacion() override;
    void aplicaMantenimiento() override;
};


#endif //PROYECTOPROGRAII_COMPUTADOR_H