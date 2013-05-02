#include "cards.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <stdio.h>

// Compara si las imágenes de dos cartas son iguales.
boolean compareCard(card card1, card card2){
    return card1.frontimg == card2.frontimg;
}

card createCard(SGE_Surface* front,int x, int y, int width, int height){
card Card1;
Card1.frontimg = front;
//Card1.x_cord = x;
//Card1.y_cord = y;
Card1.width = width;
Card1.height = height;
Card1.cardstate = 0;

return Card1;
}

// Voltea una carta.
void voltearCarta(card card1){

}
