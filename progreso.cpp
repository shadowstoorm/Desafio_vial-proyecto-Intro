#include "progreso.h"
#include <iostream>

int puntuacion = 0;

void iniciar_progreso() {
    puntuacion = 0;
}

void sumar_puntos(int puntos) {
    puntuacion += puntos;
    mostrar_puntuacion();
}

void perder_puntos(int puntos) {
    puntuacion -= puntos;
    mostrar_puntuacion();
}

void mostrar_puntuacion() {
    cout << "Puntuación actual: " << puntuacion << endl;
}
