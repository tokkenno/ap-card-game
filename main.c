/* 
 * File:        main.c
 * Description: Punto de entrada del programa. Contiene los bucles del juego.
 */

#include <stdio.h>
#include <stdlib.h>

#include <cv.h>
#include <highgui.h>

#include "imagehandler.h"

/*
 * Variables necesarias para el bucle principal del juego
 */

// Puntuacion del juego actual
int points = 0; 

/*
 * Bucle principal del juego
 */
void loopPpal()
{
    
}

/*
 * Punto de entrada del programa.
 */
int main(int argc, char** argv) {
    
    loadImage("ghoald");
    
    cvWaitKey(0);
    
    // Destruimos todas las ventanas
    cvDestroyAllWindows();

    return (EXIT_SUCCESS);
}

