/* 
 * Contiene la definicion de el tipo de dato card (carta) y las funciones
 * necesarias para su manipulacion.
 */

#ifndef CARDS_H
#define	CARDS_H

#include <cv.h>

typedef struct {
    SGE_Surface* frontimg;
    //IplImage* reverseimg; Mejor mantener un puntero a una única parte trasera en el main.
    //int x_cord;
    //int y_cord;
    int width;
    int height;
    int cardstate;                  // 0 = Volteada, 1 = Descubierta, -1 = Volteada temporalmente
    //int showstate;                   0 = Front, 1 = Reverse, 2 = ReverseHover
} card;

// Crea una carta
card createCard(SGE_Surface* front,int x, int y, int width, int height);

// Compara si las imágenes de dos cartas son iguales.
bool compareCard(card card1, card card2);

// Voltea una carta.
void voltearCarta(card card1);


#endif	/* CARDS_H */