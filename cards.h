/* 
 * Contiene la definicion de el tipo de dato card (carta) y las funciones
 * necesarias para su manipulacion.
 */

#ifndef CARDS_H
#define	CARDS_H

#include <cv.h>

typedef struct {
    IplImage* frontimg;
    IplImage* reverseimg;
    int x_cord;
    int y_cord;
    int width;
    int height;
    int cardstate;                  // 0 = Volteada, 1 = Descubierta, -1 = Volteada temporalmente
    int showstate;                  // 0 = Front, 1 = Reverse, 2 = ReverseHover
} card;

#endif	/* CARDS_H */