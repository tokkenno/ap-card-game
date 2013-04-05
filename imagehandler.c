#include <cv.h>
#include <highgui.h>

#include "imagehandler.h"
#include "dialogs.h"

IplImage* loadImage(char* path)
{
    IplImage* img;
    
    img = cvLoadImage(path, CV_LOAD_IMAGE_UNCHANGED);
    
    if (!img)
    {
        showDialog("Error", "Ha ocurrido un error al cargar una imagen.\n");
    }
    
    return img;
}
