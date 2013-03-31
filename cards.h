/* 
 * File:   cards.h
 * Author: aitor
 *
 * Created on 25 de marzo de 2013, 5:15
 */

#ifndef CARDS_H
#define	CARDS_H

#include <cv.h>

struct GameCard {
    IplImage* imgdata;
    int state;                  // 0 = Volteada, 1 = Descubierta, -1 = Volteada temporalmente
};

IplImage* loadImage(char*);

IplImage* getReverseCardImage();

#endif	/* CARDS_H */

