#include "temporizador.h"
#include <ctime>

clock_t inicio_temporizador;
double tiempo_maximo = 3.5; 

void iniciar_temporizador() {
    inicio_temporizador = clock();
}

void actualizar_tiempo() {
    
}

bool tiempo_expirado() {
    double tiempo_transcurrido = (clock() - inicio_temporizador) / (double) CLOCKS_PER_SEC;
    return tiempo_transcurrido >= tiempo_maximo;
}
