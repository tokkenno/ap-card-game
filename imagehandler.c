#include <cv.h>
#include <highgui.h>

#include "imagehandler.h"

IplImage* loadImage(char* path)
{
    IplImage* img;
    
    img = cvLoadImage(path, CV_LOAD_IMAGE_UNCHANGED);
    
    
    if (!img)
    {
        printf("LoadImage => Error mientras se cargaba una imagen.");
    }
    
    return img;
}
