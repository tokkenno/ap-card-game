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
 * @return Puntero a la ventana de juego
 */
SGE_Window* SGE_Init (char* name, int width, int height);

/**
 * Actualiza la ventana con la nueva imagen generada.
 */
void SGE_Update ();

/**
 * Descarga el SGE de memoria y cierra las ventanas.
 */
void SGE_Quit ();

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
 * @param path Ruta de la imagen
 * @return Superficio de dibujo con la imagen cargada
 */
SGE_Surface SGE_LoadImage (char* path);

/**
 * Redimensiona una superficie de trabajo (Y su contenido)
 * @param srf Superficie a redimensionar
 * @param width Nueva anchura
 * @param height Nueva altura
 */
void SGE_ResizeSurface (SGE_Surface* srf, int width, int height);

/**
 * Clona una superficie de dibujo
 * @param srf Superficie a clonar
 * @return Nueva superficie
 */
SGE_Surface SGE_CloneSurface (const SGE_Surface* srf);

/**
 * Pega una superficie de dibujo en otra
 * @param background Superficie de destino (Se modifica por referencia)
 * @param topaste Superficie de origen
 * @param position Posicion y dimensiones de destino
 */
void SGE_PasteSurface (SGE_Surface* background, const SGE_Surface* topaste, SGE_Rectangle position);

/**
 * Pega una superficie de dibujo en otra usando una mascara
 * @param background Superficie de destino (Se modifica por referencia)
 * @param topaste Superficie de origen
 * @param mask Mascara de la superficie de origen
 * @param position Posicion y dimensiones de destino
 */
void SGE_PasteSurfaceWithMask (SGE_Surface* background, const SGE_Surface* topaste, const SGE_Surface* mask, SGE_Rectangle position);

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

