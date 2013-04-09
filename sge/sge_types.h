/* 
 * Tipos de datos definidos por/para SGE
 */

#include <cv.h>

#ifndef SGE_TYPES_H
#define	SGE_TYPES_H

#ifndef NULL
/**
 * Tipo de dato NULL.
 */
#define NULL 0
#endif

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

#endif	/* SGE_TYPES_H */

