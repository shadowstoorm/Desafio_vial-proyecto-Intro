#include "semaforo.h"
#include <iostream>

using namespace std;

bool semaforo_roto = true; 
void colocar_semaforo() {
    cout << "Has colocado un nuevo semáforo en la posición actual." << endl;
    semaforo_roto = false;  
}

void reparar_semaforo() {
    if (semaforo_roto) {
        cout << "Has reparado el semáforo roto." << endl;
        semaforo_roto = false;
    } else {
        cout << "El semáforo ya está funcionando correctamente." << endl;
    }
}

bool esta_roto() {
    return semaforo_roto;
}
