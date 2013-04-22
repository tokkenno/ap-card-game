/* 
 * File:        main.c
 * Description: Punto de entrada del programa. Contiene los bucles del juego.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sge/sge.h"
#include "cards.h"
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

int main(int argc, char** argv){
    int quitcondition = 0;
	// card[] baraja;
	//llenarBaraja(&card[]);
	totalPoints = 0;
    SGE_Window* wppal;
    wppal = SGE_Init(window_name, 800, 600);

    // Bucle principal del juego
	//while (!quitcondition){
		points = 0;
		//SGE_FreeSurface(&wppal->imgWindows);
		//SGE_FreeSurface(&wppal->imgBuffer);
		//prepararTablero(&wppal);
		SGE_Surface card1 = SGE_LoadImage(cards1);
		
		SGE_Rectangle pos = SGE_CreateRectangle(dim, dim, 0, 0);

		// Pega una carta en el buffer de la pantalla
		SGE_PasteSurface(&wppal->imgBuffer, &card1, pos);
		
		// Muestra la imagen del buffer en la pantalla y lo vacia
		SGE_Update();
		
		SGE_Delay(5000);
		/*
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
	}*/
    SGE_Quit();

    return 0;
}

//Por terminar la duplicidad, pone cartas en el tablero sacándolas de la baraja. Revisar si rand()%11 repite números.
/*void prepararTablero(SGE_Window* wind,card[]* bar){
srand(time(NULL)); 
int x, int y;
	for (int x=0;x<800;x+=290){
		for (int y=0; y<600;y+=290){
			// r guarda un número al azar entre 0 y 10 para seleccionar la carta. Mirar si se repite.
			int r = rand()%11;
			//Poner una carta con coords x, y, y dimesiones 256x256
			SGE_Rectangle reg = SGE_CreateRectangle(dim,dim,x,y);
			SGE_PasteSurface(&wind->imgBuffer, &bar[r]->imgfront, reg);
			SGE_Update();
			
		}
	}
}*/

//Por completar, llena la baraja.
/*void llenarBaraja (card[]* bar){
	for (int i=0;i<10;i++){
	&bar[i]= createCard(NULL,NULL,NULL,dim,dim);
	}
}
*/