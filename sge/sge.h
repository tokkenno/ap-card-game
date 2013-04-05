/** 
 * Motor 2D simple para juegos (Simple Game Engine), implementado sobre la libreria OpenCv
 */

#ifndef SGE_H
#define	SGE_H

#include <cv.h>
#include <highgui.h>

/**
 * Estrucutura que contiene una imagen.
 */
typedef union {
    IplImage imgdata;   /**< Imagen en formato OpenCv */
} SGE_Image;

/**
 * Estructura que representa las dimensiones y posicion de una estructura restangular
 */
typedef struct SGE_Rectangle {
    int width;          /**< Ancho de la estructura */
    int height;         /**< Alto de la estructura */
    int pos_x;          /**< Coordenada x donde comienza la estructura */
    int pos_y;          /**< Coordenada y donde comienza la estructura */
} SGE_Rectangle;

/**
 * Estructura que representa el color de un pixel
 */
typedef struct SGE_Color {
    char red;           /**< Valor del color rojo de un pixel */
    char green;         /**< Valor del color verde de un pixel */
    char blue;          /**< Valor del color azul de un pixel */
    char alpha;         /**< Valor del canal alpha de un pixel */
} SGE_Color;

/**
 * Estructura que representa una superficie de dibujo
 */
typedef struct SGE_Surface {
    IplImage* imgdata;          /**< Imagen en formato OpenCv que representa lo mostrado en la pantalla */
    IplImage* paintimgdata;     /**< Imagen en formato OpenCv sobre la que se dibuja el proximo frame */
    SGE_Rectangle dimensions;   /**< Dimensiones de la superficie */
} SGE_Surface;

/**
 * Estructura que representa una ventana  
 */
typedef struct SGE_Window {
    SGE_Surface surface;        /**< Superficie de dibujado de la pantalla */
    char* title;                /**< Titulo de la ventana */
} SGE_Window;

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
 * Carga una imagen a partir de una ruta
 */
SGE_Image SGE_LoadImage (char* path);

#endif	/* SGE_H */

