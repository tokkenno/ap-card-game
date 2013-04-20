/* 
 * File:        main.c
 * Description: Punto de entrada del programa. Contiene los bucles del juego.
 */

#include <stdio.h>
#include <stdlib.h>

#include "sge/sge.h"
#include <cv.h>
#include <highgui.h>

// Nombre de la ventana del juego
static char* window_name = "ap-card-game (alpha)";
//Tamaño lateral de las cartas
static int dim = 256;
// Puntuacion del juego actual
int points = 0;
//Primera carta del deck
static char* cards1 = "/home/aitor/Desarrollo/APCardGame/dist/Debug/GNU-Linux-x86/decks/animals/01.png";
// Punto de entrada del programa.

int main(int argc, char** argv) {
    int quitcondition = 0;
    SGE_Window* wppal;
    wppal = SGE_Init(window_name, 800, 600);

    // Bucle principal del juego
    
    SGE_Surface card1 = SGE_LoadImage(cards1);
    
    SGE_Rectangle pos = SGE_CreateRectangle(dim, dim, 0, 0);

    // Pega una carta en el buffer de la pantalla
    SGE_PasteSurface(&wppal->imgBuffer, &card1, pos);
    
    // Muestra la imagen del buffer en la pantalla y lo vacia
    SGE_Update();
    
    SGE_Delay(5000);
    
    SGE_Quit();

    return 0;
}

