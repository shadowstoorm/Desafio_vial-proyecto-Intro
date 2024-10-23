#include "ingeniero_transito.h"
#include "semaforo.h"   // Importa funciones de semáforo
#include "senales.h"    // Importa funciones de señales
#include <iostream>

using namespace std;

int pos_x = 0;
int pos_y = 0;

void mover_arriba() {
    pos_y++;
    cout << "Te has movido hacia arriba. Posición actual: (" << pos_x << ", " << pos_y << ")" << endl;
}

void mover_abajo() {
    pos_y--;
    cout << "Te has movido hacia abajo. Posición actual: (" << pos_x << ", " << pos_y << ")" << endl;
}

void mover_izquierda() {
    pos_x--;
    cout << "Te has movido hacia la izquierda. Posición actual: (" << pos_x << ", " << pos_y << ")" << endl;
}

void mover_derecha() {
    pos_x++;
    cout << "Te has movido hacia la derecha. Posición actual: (" << pos_x << ", " << pos_y << ")" << endl;
}

void interactuar() {
    if (esta_roto()) {
        reparar_semaforo();
    } else {
        cout << "No hay nada con lo que interactuar aquí." << endl;
    }
}




