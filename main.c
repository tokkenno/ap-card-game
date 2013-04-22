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
// Puntuación de juego en esta sesión
int totalPoints = 0;
//Primera carta del deck
static char* cards1 = "/home/aitor/Desarrollo/APCardGame/dist/Debug/GNU-Linux-x86/decks/animals/01.png";
// Punto de entrada del programa.

int main(int argc, char** argv) {
    int quitcondition = 0;
    SGE_Window* wppal;
    wppal = SGE_Init(window_name, 800, 600);

    // Bucle principal del juego
	while (!quitcondition){
		points = 0;
		
		SGE_Surface card1 = SGE_LoadImage(cards1);
		
		SGE_Rectangle pos = SGE_CreateRectangle(dim, dim, 0, 0);

		// Pega una carta en el buffer de la pantalla
		SGE_PasteSurface(&wppal->imgBuffer, &card1, pos);
		
		// Muestra la imagen del buffer en la pantalla y lo vacia
		SGE_Update();
		
		SGE_Delay(5000);
		
		//Una vez preparado el tablero, jugamos. Guardamos el número de cartas diferentes en int cardNumber. 
		
		printf("Selecciona una carta");
		//El usuario ha seleccionado una carta. cardState = -1 (la volteamos temporalmente)
		printf("Busca su pareja");
		//Esperamos 10 segundos.
		SGE_Delay(10000);
		//Si se seleccionó una segunda carta, voltear y hacer la comparación.
			//Si el resultado de la comparación es false, volver ambas cartas a su estado inicial. cardState = 0;
			//Si el resultado de la comparación es true, poner cardstate a 1, y dejar ambas boca arriba. cardState = 1; points++; totalPoints++;
		//Si no se seleccionó ninguna carta, volver la carta a su estado inicial.
		
		
		//Si se han acabado las cartas	
		if (cardNumber == points){
		//Pregunta al usuario si quiere volver a jugar.
		char answer;
		printf("Has ganado. ¡Enhorabuena!");
		printf("¿Quieres volver a jugar? S/N");
		scanf("%c",answer);
		if ((answer == N) || (answer == n)) quitcondition = 1;
		}
	}
    SGE_Quit();

    return 0;
}

