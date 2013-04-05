/* 
 * Motor 2D simple para juegos (Simple Game Engine), implementado sobre
 * la libreria OpenCv
 */

#ifndef SGE_H
#define	SGE_H

#include <cv.h>
#include <highgui.h>

typedef union {
    IplImage imgdata;
} SGE_Image;

typedef struct SGE_Rectangle {
    int width;
    int height;
    int pos_x;
    int pos_y;
} SGE_Rectangle;

typedef struct SGE_Color {
	char red;
	char green;
	char blue;
	char alpha;
} SGE_Color;

typedef struct SGE_Surface {
    IplImage* imgdata;
    IplImage* paintimgdata;
    SGE_Rectangle dimensions;
} SGE_Surface;

typedef struct SGE_Window {
    SGE_Surface surface;
    char* title;
} SGE_Window;

SGE_Window SGE_Init (char* name, int width, int height);

void SGE_Update (SGE_Window w);

void SGE_Quit (SGE_Window w);

SGE_Surface SGE_CreateSurface (int width, int height);

SGE_Image SGE_LoadImage (char* path);

#endif	/* SGE_H */

