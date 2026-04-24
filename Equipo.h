

#ifndef PROYECTOPROGRAII_EQUIPO_H
#define PROYECTOPROGRAII_EQUIPO_H
#include <iostream>
using namespace std;

class Equipo {
protected:
    string id;
    float estado;
    int tiempoInactivo;
    int criticidad;
    int incidenciasActivas;
public:
    Equipo(string, float, int, int, int);
    Equipo();
    virtual ~Equipo();
    //Gets y sets
    void setId(string);
    string getId();
    void setEstado(float);
    float getEstado();
    void setTiempoInactivo(int);
    int getTiempoInactivo();
    void setCriticidad(int);
    int getCriticidad();
    void setIncidenciasActiva(int);
    int getIncidenciasActiva();
    //Metodos
    virtual float calcularPrioridad() = 0;
    virtual void aplicaDegradacion() = 0;
    virtual void aplicaMantenimiento() = 0;
};


#endif //PROYECTOPROGRAII_EQUIPO_H