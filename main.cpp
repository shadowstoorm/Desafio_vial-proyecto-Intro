#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#ifdef _WIN32
    #include <windows.h>
#else

#endif
#include <conio.h>

using namespace std;

// Variables globales
bool semaforo_roto = true;
bool enemigo_presente = false;
clock_t inicio_temporizador;
double tiempo_maximo = 3.5;
int puntuacion = 0;
int pos_x = 0;
int pos_y = 0;


void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls"); 
    #endif
}

void cambiar_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

#include <iostream>
using namespace std;

void mostrar_presentacion() {
     for (int i = 0; i < 15; i++) {
        cout << endl;
    }
    cambiar_color(4);
    cout << "                                ________  _______   ________  ________  ________ ___  ________          ___      ___ ___  ________  ___          " << endl;
    cout << "                                |\\   ___ \\|\\  ___ \\ |\\   ____\\|\\   __  \\|\\  _____\\\\  \\|\\   __  \\        |\\  \\    /  /|\\  \\|\\   __  \\|\\  \\         " << endl;
    cout << "                                \\ \\  \\_|\\ \\ \\   __/|\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\__/\\ \\  \\ \\  \\|\\  \\       \\ \\  \\  /  / | \\  \\ \\  \\|\\  \\ \\  \\        " << endl;
    cout << "                                 \\ \\  \\ \\\\ \\ \\  \\_|/_\\ \\_____  \\ \\   __  \\ \\   __\\\\ \\  \\ \\  \\\\\\  \\       \\ \\  \\/  / / \\ \\  \\ \\   __  \\ \\  \\       " << endl;
    cout << "                                  \\ \\  \\_\\\\ \\ \\  \\_|\\ \\|____|\\  \\ \\  \\ \\  \\ \\  \\_| \\ \\  \\ \\  \\\\\\  \\       \\ \\    / /   \\ \\  \\ \\  \\ \\  \\ \\  \\____  " << endl;
    cout << "                                   \\ \\_______\\ \\_______\\____\\_\\  \\ \\__\\ \\__\\ \\__\\   \\ \\__\\ \\_______\\       \\ \\__/ /     \\ \\__\\ \\__\\ \\__\\ \\_______\\" << endl;
    cout << "                                    \\|_______|\\|_______|\\_________\\|__|\\|__|\\|__|    \\|__|\\|_______|        \\|__|/       \\|__|\\|__|\\|__|\\|_______|" << endl;
    cout << "                                                           \\|_________|                                                                                " << endl;

}


// Función para mostrar el menú
void mostrar_menu() {
    for (int i = 0; i < 15; i++) {
        cout << endl;
    }
    cambiar_color(6);
    cout << "                                                        __    __     ______     __   __     __  __    " << endl;
    cout << "                                                       /\\ \"-./  \\   /\\  ___\\   /\\ \"-.\ \\   /\\ \\/\\ \\   " << endl;
    cout << "                                                       \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\  " << endl;
    cout << "                                                        \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\"\\_\\  \\ \\_____\\ " << endl;
    cout << "                                                         \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/  " << endl;
    cout << "                                                        --------------------------------------------------" << endl;
    cout << "                                                        Presiona 'Enter' para mostrar las instrucciones" << endl;
}

// Función para mostrar las instrucciones
void mostrar_instrucciones() {
    for (int i = 0; i < 15; i++) { 
        cout << endl;
    }
    cambiar_color(2);
    cout << "                                              ________  ________  ________   _________  ________  ________  ___       _______   ________      \n";
    cout << "                                             |\\   ____\\|\\   __  \\|\\   ___  \\|\\___   ___\\\\   __  \\|\\   __  \\|\\  \\     |\\  ___ \\ |\\   ____\\     \n";
    cout << "                                             \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\ \\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\    \\ \\   __/|\\ \\  \\___|_    \n";
    cout << "                                              \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\ \\  \\   \\ \\  \\ \\ \\   _  _\\ \\  \\\\\\  \\ \\  \\    \\ \\  \\_|/_\\ \\_____  \\   \n";
    cout << "                                               \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\\\ \\  \\   \\ \\  \\ \\ \\  \\\\  \\\\\\  \\ \\  \\\\  \\ \\  \\____\\ \\  \\_|\\ \\|____|\\  \\  \n";
    cout << "                                                \\ \\_______\\ \\_______\\ \\__\\\\ \\__\\   \\ \\__\\ \\ \\__\\\\ _\\\\ \\_______\\ \\_______\\ \\_______\\____\\_\\  \\ \n";
    cout << "                                                 \\|_______|\\|_______|\\|__| \\|__|    \\|__|  \\|__|\\|__|\\|_______|\\|_______|\\|_______|\\_________\\\n";
    cout << "                                                                                                                                                         \n";

    cout << "                                                        w: mover arriba\n"
         << "                                                        s: mover abajo\n"
         << "                                                        a: mover izquierda\n"
         << "                                                        d: mover derecha\n"
         << "                                                        f: interactuar (arreglar semáforo, colocar señal)\n"
         << "                                                        c: colocar semáforo nuevo\n"
         << "                                                        e: pedir refuerzos\n";
      cambiar_color(9);
}


  
// Funciones de semáforo
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

// Funciones del ingeniero de tránsito
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

// Funciones de enemigos
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

// Funciones de temporizador
void iniciar_temporizador() {
    inicio_temporizador = clock();
}

bool tiempo_expirado() {
    double tiempo_transcurrido = (clock() - inicio_temporizador) / (double) CLOCKS_PER_SEC;
    return tiempo_transcurrido >= tiempo_maximo;
}

// Funciones de señales
void colocar_senal_no_derecha() {
    cout << "Has colocado una señal de 'No girar a la derecha' en la posición actual." << endl;
}

void colocar_senal_stop() {
    cout << "Has colocado una señal de 'Stop' en la posición actual." << endl;
}

void colocar_senal_ceda_paso() {
    cout << "Has colocado una señal de 'Ceda el paso' en la posición actual." << endl;
}

void colocar_senal_limite_velocidad(int limite) {
    cout << "Has colocado una señal de 'Límite de velocidad: " << limite << " km/h' en la posición actual." << endl;
}

void colocar_senal_zona_escolar() {
    cout << "Has colocado una señal de 'Zona escolar' en la posición actual." << endl;
}

// Funciones de progreso
void iniciar_progreso() {
    puntuacion = 0;
}

void mostrar_puntuacion() {
    cout << "Puntuación actual: " << puntuacion << endl;
}

void sumar_puntos(int puntos) {
    puntuacion += puntos;
    mostrar_puntuacion();  
}

void perder_puntos(int puntos) {
    puntuacion -= puntos;
    mostrar_puntuacion();  
}

void fondo_nivel1(){
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "================================================================================\n";
    cout << "                                                                                \n";
    cout << "          ==========          ===========       ============          ==========\n";
    cout << "                                                                                \n";
    cout << "================================================================================\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
    cout << "                              ||      ||      ||\n";
}

// Función principal
int main() {
    mostrar_presentacion();
    cin.get();     
    limpiar_pantalla();
    mostrar_menu(); 
    cin.get();
    limpiar_pantalla();
    mostrar_instrucciones();
 

    _getch();
    return 0;
}






