//
// Created by andre on 24/4/2026.
//

#include "Ordenamiento.h"

void Ordenamiento::mergeSort(Equipo** equipos, int inicio, int fin) {
    if (inicio >= fin)
        return;

    int medio = (inicio + fin) / 2;
    mergeSort(equipos, inicio, medio);
    mergeSort(equipos, medio + 1, fin);

    merge(equipos, inicio, medio, fin);
}

void Ordenamiento::merge(Equipo** equipos, int inicio, int medio, int fin) {
        int tIzquierda = medio - inicio + 1;
        int tDerecha = fin - medio;

        Equipo** izquierda = new Equipo*[tIzquierda];
        Equipo** derecha = new Equipo*[tDerecha];

        for (int i = 0; i < tIzquierda; i++)
            izquierda[i] = equipos[inicio + i];
        for (int j = 0; j < tDerecha; j++)
            derecha[j] = equipos[medio + 1 + j];

        int i = 0, j = 0, k = inicio;

        while (i < tIzquierda && j < tDerecha) {
            if (izquierda[i]->calcularPrioridad() >= derecha[j]->calcularPrioridad()) {
                equipos[k] = izquierda[i];
                i++;

            } else {
                equipos[k] = derecha[j];
                j++;
            }
            k++;
        }

        while (i < tIzquierda) {
            equipos[k] = izquierda[i];
            k++;
            i++;
        }
        while (j < tDerecha) {
            equipos[k] = derecha[j];
            k++;
            j++;
        }

        delete[] izquierda;
        delete[] derecha;
}

void Ordenamiento::ordenar(Equipo** equipos, int cantidad) {
    if (cantidad <= 1) return;
    mergeSort(equipos, 0, cantidad - 1);
}
