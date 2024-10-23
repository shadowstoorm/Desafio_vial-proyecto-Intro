#include <iostream>
#include "ingeniero_transito.h"
#include "semaforo.h"
#include "senales.h"
#include "enemigos.h"
#include "progreso.h"
#include "temporizador.h"

using namespace std;

void mostrar_presentacion() {
    cout << "██████  ███████ ███████  █████  ███████ ██  ██████     ██    ██ ██  █████  ██      " << endl;
    cout << "██   ██ ██      ██      ██   ██ ██      ██ ██    ██     ██    ██ ██ ██   ██ ██      " << endl;
    cout << "██   ██ █████   ███████ ███████ █████   ██ ██    ██     ██    ██ ██ ███████ ██      " << endl;
    cout << "██   ██ ██           ██ ██   ██ ██      ██ ██    ██      ██  ██  ██ ██   ██ ██      " << endl;
    cout << "██████  ███████ ███████ ██   ██ ██      ██  ██████        ████   ██ ██   ██ ███████ " << endl;
}

void mostrar_instrucciones() {
    cout << "Nivel 1: Coloca y arregla semáforos, señales de tráfico y enfrenta a los conductores borrachos.\n";
    cout << "Controles: \n"
         << "w: mover arriba\n"
         << "s: mover abajo\n"
         << "a: mover izquierda\n"
         << "d: mover derecha\n"
         << "f: interactuar (arreglar semáforo, colocar señal)\n"
         << "c: colocar semáforo nuevo\n"
         << "e: pedir refuerzos\n";
}

int main() {
    mostrar_presentacion();
    mostrar_instrucciones();
    iniciar_progreso();
    
    char accion;
    bool jugando = true;

    while (jugando) {
        actualizar_tiempo(); 
        if (aparece_enemigo()) { 
            iniciar_temporizador();
            cout << "¡Un conductor borracho ha aparecido! Tienes 3 segundos para pedir refuerzos (presiona 'e')." << endl;
        }

        cin >> accion;

        switch(accion) {
            case 'w': mover_arriba(); break;
            case 's': mover_abajo(); break;
            case 'a': mover_izquierda(); break;
            case 'd': mover_derecha(); break;
            case 'f': interactuar(); sumar_puntos(50); break;  
            case 'c': colocar_semaforo(); sumar_puntos(100); break; 
            case 'e': pedir_refuerzos(); break; 
            case 'q': jugando = false; break;
            default: cout << "Acción no válida." << endl;
        }

        if (tiempo_expirado()) { 
            cout << "El conductor borracho escapó y perdiste puntos." << endl;
            perder_puntos(50);
        }
    }

    return 0;
}





