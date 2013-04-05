#include "sge.h"

#include <cv.h>
#include <highgui.h>

SGE_Window SGE_Init (char* title, int width, int height)
{
    SGE_Window toret;
    
    toret.surface = SGE_CreateSurface (width, height);
    toret.title = title;
    
    cvNamedWindow(title, CV_WINDOW_AUTOSIZE);
    cvShowImage(title, toret.surface.imgdata);
    
    // Tenemos que esperar a que el otro hilo cree la ventana asincronamente.
    // Como OpenCv no ofrece una funcion para ello, nos "apañamos" esperando un rato.
    cvWaitKey(200);
    
    return toret;
}

void SGE_Update (SGE_Window w)
{
    cvWaitKey(200);
    if (w.surface.paintimgdata != NULL)
    {
        cvReleaseImage(&w.surface.imgdata);
        w.surface.imgdata = w.surface.paintimgdata;
        w.surface.paintimgdata = NULL;
        cvShowImage(w.title, w.surface.imgdata);
    }
}

void SGE_Quit (SGE_Window w)
{
    cvDestroyWindow(w.title);
    cvReleaseImage(&w.surface.imgdata);
    
    cvDestroyAllWindows();
}

SGE_Surface SGE_CreateSurface (int width, int height)
{
    SGE_Surface toret;
    
    toret.imgdata = cvCreateImage(cvSize(width, height), 16, 4);
    toret.paintimgdata = NULL;
    
    SGE_Rectangle dim;
    dim.width = width;
    dim.height = height;
    dim.pos_x = 0;
    dim.pos_y = 0;
    
    toret.dimensions = dim;
    
    return toret;
}

SGE_Image SGE_LoadImage (char* path)
{
    SGE_Image toret;
    IplImage* img;
    
    img = cvLoadImage(path, CV_LOAD_IMAGE_UNCHANGED);
    
    
    if (!img)
    {
        printf("SGE_LoadImage => Error mientras se cargaba una imagen.");
    }
    
    toret.imgdata = *img;
    return toret;
}