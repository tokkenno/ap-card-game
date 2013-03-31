#include <cv.h>
#include <highgui.h>

#include "cards.h"
#include "dialogs.h"

const char* reverseCardImagePath = "images/reverse.png";
const char* facesCardImagePath = "images/faces/";

IplImage* loadImage(char* path)
{
    IplImage* img = cvLoadImage(path, -1);
    
    if (!img)
    {
        showDialog("Error", "Ha ocurrido un error al cargar una imagen.\n");
    }
    
    return img;
}

IplImage* getReverseCardImage()
{
    
}