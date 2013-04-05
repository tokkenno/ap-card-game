/* 
 * Agrupa todas las funciones de carga, descarga y manejo de imagenes.
 */

#ifndef IMAGEHANDLER_H
#define	IMAGEHANDLER_H

#include <cv.h>

// Carga una imagen a partir de una ruta y muestra un mensage de error
// en caso de que algo haya ido mal.
IplImage* loadImage(char*);

#endif	/* IMAGEHANDLER_H */

