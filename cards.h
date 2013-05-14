/* 
 * Contiene la definicion de el tipo de dato card (carta) y las funciones
 * necesarias para su manipulacion.
 */

#ifndef CARDS_H
#define	CARDS_H

#include <opencv/cv.h>
#include "sge/sge_types.h"

typedef struct {
    int x;
    int y;
} coord;

typedef struct {
    char* frontimg;
    coord pos1; //Posición del primer ejemplar en el tablero. Default = -1,-1
    coord pos2; //Posición del segundo ejemplar en el tablero. Default = -1,-1
    int width;
    int height;
    int cardstate; // 0 = Volteada, 1 = Descubierta, -1 = Volteada temporalmente

} card;

// Crea una carta
card createCard(char* front, int width, int height);

void setC1(int x,int y,card* C);
void setC2(int x,int y,card* C);
// Compara si las imágenes de dos cartas son iguales.
boolean compareCard(card card1, card card2);



#endif	/* CARDS_H */
