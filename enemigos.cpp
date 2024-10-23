#include "enemigos.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

bool enemigo_presente = false;

bool aparece_enemigo() {
    int probabilidad = rand() % 10;
    if (probabilidad == 0) {
        enemigo_presente = true;
        return true;
    }
    return false;
}

void pedir_refuerzos() {
    if (enemigo_presente) {
        cout << "Has pedido refuerzos. El conductor borracho ha sido arrestado." << endl;
        enemigo_presente = false;
    } else {
        cout << "No hay ningún conductor borracho presente." << endl;
    }
}
