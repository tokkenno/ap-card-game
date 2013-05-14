/* 
 * File:        main.c
 * Description: Punto de entrada del programa. Contiene los bucles del juego.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sge/sge.h"
#include "cards.h"
#include "strhelper.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>



const int alphaMascara = 255;//negro
const int colorMascara = 0;//blanco

// Nombre de la ventana del juego
static char* window_name = "ap-card-game (alpha)";

// Parte de atrás de las cartas
static char* card0 = "C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/00.png";

//Tamaño lateral de las cartas
static int dim = 256;

// Puntuacion del juego actual
int points = 0;

// Puntuación de juego en esta sesión
int totalPoints = 0;


//Por adaptar
IplImage* cardMask(IplImage* fuente){
    return 0;
}
//Por adaptar
void pasteCardWithFade(IplImage* tablero,IplImage* card,IplImage* mask,int x, int y){

}

//Pone la parte de la imagen inicial desde x,y hasta x+dim,y+dim con los datos de la imagen final.
//Utilizable para voltear cartas con fade(requerido).
//Necesitamos pasarlo a SSE2 (¿alguien lo tiene?)
void fade(IplImage * Img, IplImage * Img2, int pos_x, int pos_y, int n) {
    //Pixel de img1 * n + pixel de img2 * (1-n) (n=1,0.9,0.8,0.7...)
    int fila, columna;
     
    
        for (fila = pos_y; fila < pos_y + dim; fila++) {
            unsigned char *pImg = (unsigned char *) Img->imageData + fila * Img->widthStep;
            unsigned char *pImg2 = (unsigned char *) Img2->imageData + fila * Img2->widthStep;
            for (columna = pos_x; columna < pos_x + dim; columna++) {
                pImg[columna * 3] = pImg[columna * 3] * n + pImg2[columna * 3] * (1 - n);
                pImg[columna * 3 + 1] = pImg[columna * 3 + 1] * n + pImg2[columna * 3 + 1] * (1 - n);
                pImg[columna * 3 + 2] = pImg[columna * 3 + 2] * n + pImg2[columna * 3 + 2] * (1 - n);
            }
        }
        
    

}

void prepararTablero(IplImage* tablero, card* bar[16]) {
   
    //EN PROCESO, SE BUSCAN IDEAS PARA ESCOGER DONDE PONER LA SEGUNDA CARTA DE MANERA RANDOM
     srand(time(NULL));
    int x, y;
    for (x = 0; x < 800; x += 260) {
        for (y = 0; y < 600; y += 260) {
            // r guarda un número al azar entre 0 y 10 para seleccionar la carta. Mirar si se repite.
            int r = rand() % 11;
            //Asignamos las coordenadas a la carta
            setC1(x, y, bar[r]);
            //setC2(x,y,bar[r]);

        }
    }
}

void mostrarIMG(IplImage * Img) {
    cvNamedWindow("Imagen", 1);
    cvShowImage("Imagen", Img);
    cvWaitKey(0);
    cvReleaseImage(&Img);
    cvDestroyWindow("Imagen");
}

void llenarBaraja(card * baraja[12]) {
    int i;
    char* paths[12];
    paths[0]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/00.png";
    paths[1]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/01.png";
    paths[2]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/02.png";
    paths[3]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/03.png";
    paths[4]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/04.png";
    paths[5]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/05.png";
    paths[6]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/06.png";
    paths[7]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/07.png";
    paths[8]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/08.png";
    paths[9]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/09.png";
    paths[10]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/10.png";
    paths[11]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/11.png";
    paths[12]="C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/12.png";
    
    //char buffer[20];
    printf("\nCargando cartas...");
    for (i = 1; i < 13; i++) {
        baraja[i]->frontimg = paths[i];
        printf("\nCarta cargada: %c",  paths[i]);
        
       //Si conseguimos hacer la conversión, usar
        /*
        char* str1 = "C:/Users/Usuario/Documents/NetBeansProjects/ap-card-game/decks/animals/0";
        char* str2=(char*) i;
        char* str3 = ".png";
        str2 = strconcat(str1, str2);
        str1 = strconcat(str2, str3);
         */
    }
}
// Punto de entrada del programa.
int main(int argc, char** argv) {
    int quitcondition = 0;
    card * baraja[12];
    //Llenamos la bajara desde el repositorio local
     //llenarBaraja(baraja);
    IplImage* Background = cvLoadImage(card0, CV_LOAD_IMAGE_UNCHANGED);
    if (!Background) {
        printf("Error: fichero %s no leido\n", card0);
        return EXIT_FAILURE;
    }
    /*IplImage* Card1 = cvLoadImage(card0, CV_LOAD_IMAGE_UNCHANGED);
    if (!Card1) {
        printf("Error: fichero %s no leido\n", card0);
        return EXIT_FAILURE;
    }*/
    mostrarIMG(Background);
    totalPoints = 0;

    // Bucle principal del juego
    //while (!quitcondition) {
        points = 0;

        //IplImage* tablero = NULL;
        //tablero = cvCreateImage(cvSize(800, 600), 16, 4);
        //prepararTablero(tablero,baraja);
        int cardNumber = 12;

        //Una vez preparado el tablero, jugamos. Guardamos el número de cartas diferentes en int cardNumber. 
        //printf("\nSelecciona una carta.");
        //El usuario ha seleccionado una carta. cardState = -1 (la volteamos temporalmente)
        //printf("\nBusca su pareja.");
        //Esperamos 10 segundos.
        //SGE_Delay(10000);
        //Si se seleccionó una segunda carta, voltear y hacer la comparación.
        //Si el resultado de la comparación es false, volver ambas cartas a su estado inicial. cardState = 0;
        //Si el resultado de la comparación es true, poner cardstate a 1, y dejar ambas boca arriba. cardState = 1; points++; totalPoints++;
        //Si no se seleccionó ninguna carta, volver la carta a su estado inicial.
        //Si se han acabado las cartas	

        /*if (cardNumber == points) {
            //Pregunta al usuario si quiere volver a jugar.
            char answer;
            printf("\nHas ganado. ¡Enhorabuena!");
            printf("\n¿Quieres volver a jugar? S/N");
            scanf("%c", &answer);
            if ((answer == 'N') || (answer == 'n')) quitcondition = 1;
        }*/

    //}
    return EXIT_SUCCESS;
}
