#include <highgui.h>

#include "dialogs.h"

void showDialog (char* title, char* text)
{
    cvNamedWindow(title, CV_WINDOW_AUTOSIZE);
    
    CvFont font;
    cvInitFont( &font, CV_FONT_VECTOR0, 0.5, 0.5, 0, 2.0, CV_AA);
    
    
    cvWaitKey(5000);
    
    cvDestroyWindow(title);
}