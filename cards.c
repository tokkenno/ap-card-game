#include "cards.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <stdio.h>

// Compara si las imágenes de dos cartas son iguales.

boolean compareCard(card card1, card card2) {
    return card1.frontimg == card2.frontimg;
}
void setC1(int x,int y,card* C){
    C->pos1.x=x;
    C->pos1.y=y;
}
void setC2(int x,int y,card* C){
    C->pos2.x=x;
    C->pos2.y=y;
}

card createCard(char* front, int width, int height){
    card Card1;
    Card1.frontimg = front;
    Card1.pos1.x = -1;
    Card1.pos1.y = -1;
    Card1.pos2.x = -1;
    Card1.pos2.y = -1;
    Card1.width = width;
    Card1.height = height;
    Card1.cardstate = 0;

    return Card1;
}


