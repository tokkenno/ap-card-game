/** 
 * Motor 2D simple para juegos (Simple Game Engine), implementado sobre la libreria OpenCv
 */

#ifndef SGE_H
#define	SGE_H

#include <cv.h>
#include <highgui.h>
#include "sge_types.h"

/**
 * Inicializa el SGE y crea una ventana para el juego.
 * @param name Titulo de la ventana
 * @param width Ancho de la ventana destino
 * @param height Alto de la ventana destino
 * @return Ventana en formato SGE
 */
SGE_Window* SGE_Init (char* name, int width, int height);

/**
 * Actualiza la ventana con la nueva imagen generada.
 */
void SGE_Update (SGE_Window* w);

/**
 * Descarga el SGE de memoria y cierra las ventanas.
 */
void SGE_Quit (SGE_Window* w);

/**
 * Crea una superficie de dibujo
 */
SGE_Surface SGE_CreateSurface (int width, int height);

/**
 * Libera los recursos usados por una superficie
 * @param srf Puntero a la superficie
 */
void SGE_FreeSurface(SGE_Surface* srf);

/**
 * Carga una imagen a partir de una ruta
 */
SGE_Surface SGE_LoadImage (char* path);

#pragma region Funciones de tiempo

/**
 * Obtiene el numero de milisegundos desde que se ha inicializado el SGE
 * @return Milisegundos
 */
unsigned long SGE_GetTicks ();

/**
 * Detiene el programa durante un tiempo determinado
 * @param ms Tiempo en milisegundos
 */
void SGE_Delay (unsigned long ms);

#pragma endregion

#endif	/* SGE_H */

