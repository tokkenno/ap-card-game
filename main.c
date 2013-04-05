/* 
 * File:        main.c
 * Description: Punto de entrada del programa. Contiene los bucles del juego.
 */

#include <stdio.h>
#include <stdlib.h>

#include "sge/sge.h"

// Nombre de la ventana del juego
static char* window_name = "ap-card-game (alpha)";

// Puntuacion del juego actual
int points = 0;

// Punto de entrada del programa.
int main(int argc, char** argv) {
    int quitcondition = 0;
    SGE_Window wppal = SGE_Init(window_name, 600, 400);
    
    // Bucle principal del juego
    while(!quitcondition)
    {
    }
    
    SGE_Quit(wppal);

    return 0;
}

