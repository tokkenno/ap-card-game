/* 
 * File:        main.c
 * Description: Punto de entrada del programa. Contiene los bucles del juego.
 */

#include <stdio.h>
#include <stdlib.h>

#include "sge/sge.h"

// Nombre de la ventana del juego
static char* window_name = "ap-card-game (alpha)";
//Tamaño lateral de las cartas
static int dim = 256;
// Puntuacion del juego actual
int points = 0;
//Primera carta del deck
static char* cards1 = "/decks/animals/01.png";
// Punto de entrada del programa.

int main(int argc, char** argv) {
    int quitcondition = 0;
    SGE_Window wppal;
    wppal = SGE_Init(window_name, 800, 600);

    // Bucle principal del juego
    
        SGE_Surface* bkg;
        *bkg = SGE_CreateSurface(800, 600);
        SGE_Surface* card1;
        *card1=SGE_LoadImage(cards1);
        
        int x, y;
        SGE_Rectangle pos;
        pos.width = dim;
        pos.height = dim;
        
        for (x = 0; x < 800; x += 400)  
            for (y = 0; y < 600; y += 300) {
                pos.pos_x = x;
                pos.pos_y = y;
                SGE_PasteSurface(bkg, card1, pos);
            }
        
        
        SGE_Update(&wppal);
        cvWaitKey(5000);
    

    SGE_Quit(&wppal);

    return 0;
}

