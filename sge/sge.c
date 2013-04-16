#include "sge.h"
#include "sge_types.h"
#include "cpuinfo/sge_cpuinfo.h"

#include <cv.h>
#include <highgui.h>

// Como el programa elige que set de instrucciones usar en tiempo de ejecucion, se compila
// con todas las instrucciones.
#include <emmintrin.h>
#include <xmmintrin.h>

SGE_Window SGE_Init (char* title, int width, int height)
{
    SGE_Window toret;
    
    toret.imgBuffer = SGE_CreateSurface (width, height);
    toret.imgWindow = toret.imgBuffer;
    toret.title = title;
    
    cvNamedWindow(title, CV_WINDOW_AUTOSIZE);
    cvShowImage(title, toret.imgWindow.imgData);
    
    // Tenemos que esperar a que el otro hilo cree la ventana asincronamente.
    // Como OpenCv no ofrece una funcion para ello, nos "apañamos" esperando un rato.
    cvWaitKey(200);
    
    return toret;
}

void SGE_Update (SGE_Window* w)
{
    cvWaitKey(200);
    if (&w->imgBuffer != NULL && w->imgBuffer.imgData != w->imgWindow.imgData)
    {
        SGE_FreeSurface(&w->imgWindow);
        w->imgWindow = w->imgBuffer;
        w->imgBuffer = SGE_CloneSurface(&w->imgWindow);
        cvShowImage(w->title, w->imgWindow.imgData);
    }
}

void SGE_Quit (SGE_Window* w)
{
    cvDestroyWindow(w->title);
    
    SGE_FreeSurface(&w->imgWindow);
    SGE_FreeSurface(&w->imgBuffer);
    
    cvDestroyAllWindows();
}

SGE_Surface SGE_CreateSurface (int width, int height)
{
    SGE_Surface toret;
    
    toret.imgData = cvCreateImage(cvSize(width, height), 16, 4);
    
    SGE_Rectangle dim;
    dim.width = width;
    dim.height = height;
    dim.pos_x = 0;
    dim.pos_y = 0;
    
    toret.dimensions = dim;
    
    return toret;
}

void SGE_FreeSurface(SGE_Surface* srf)
{
    cvReleaseImage(&srf->imgData);
    srf = NULL;
}

SGE_Surface SGE_LoadImage (char* path)
{
    SGE_Surface toret;
    SGE_Rectangle dim;
    IplImage* img;
    
    img = cvLoadImage(path, CV_LOAD_IMAGE_UNCHANGED);
    
    if (!img)
    {
        printf("SGE_LoadImage => Error mientras se cargaba una imagen.\n");
    }
    
    dim.pos_x = dim.pos_y = 0;
    dim.height = img->height;
    dim.width = img->width;
    
    toret.dimensions = dim;
    toret.imgData = img;
    return toret;
}

void SGE_ResizeSurface (SGE_Surface* srf, int width, int height)
{
    if (srf->imgData->height != height || srf->imgData->width != width)
    {
        SGE_Surface aux = SGE_CreateSurface (width, height);
        cvResize (srf->imgData, aux.imgData, CV_INTER_CUBIC);
        cvReleaseImage(&srf->imgData);
        srf->imgData = cvCloneImage(aux.imgData);
        SGE_FreeSurface(&aux);
    }
}

SGE_Surface SGE_CloneSurface (const SGE_Surface* srf)
{
    SGE_Surface toret;
    
    toret.imgData = cvCloneImage(srf->imgData);
    toret.dimensions = srf->dimensions;
    
    return toret;
}

// Funcion privada que pega una superficie sobre otra usando instrucciones SSE
void SGE_PasteSurfaceWithMaskSSE2 (SGE_Surface* background, const SGE_Surface* topaste, const SGE_Surface* mask, SGE_Rectangle position)
{
   int index, jindex;
   __m128i pixel, pixelMask, pixelBg, *bgPointer, *tpPointer, *msPointer;
   
   bgPointer = (__m128i*) background->imgData->imageData;
   tpPointer = (__m128i*) topaste->imgData->imageData;
   if (mask != NULL)
       msPointer = (__m128i*) mask->imgData->imageData;
   
   int ylimit, xlimit;
   if ((ylimit = position.height + position.pos_y) > background->dimensions.height)
       ylimit = background->dimensions.height;
   if ((xlimit = position.width + position.pos_x) > background->dimensions.width)
       xlimit = background->dimensions.width;
   
    // Comprobamos si la mascara es nula para poder optimizar el proceso
    if (mask == NULL)
    {
        for(index = position.pos_y; index < ylimit; index++)
        {
            bgPointer = (__m128i*)(background->imgData->imageData + index * 4);

            for(jindex = position.pos_x; jindex < xlimit; jindex+=4)
            {
                *bgPointer++ = *tpPointer++;
            }
        }
    }
    else
    {
        for(index = position.pos_y; index < ylimit; index++)
        {
            bgPointer = (__m128i*)(background->imgData->imageData + index * 4);

            for(jindex = position.pos_x; jindex < xlimit; jindex+=4)
            {
                pixel = *tpPointer++;           // Valor de un pixel de la imagen a pegar
                pixelMask = *msPointer++;       // Valor de la mascara en ese pixel
                pixelBg = *bgPointer;           // Valor del fondo en ese pixel
                
                pixel = _mm_andnot_si128(pixelMask, pixel);             // (topaste || mask)
                __m128i auxp = _mm_and_si128(pixelBg, pixelMask);       // (background && mask)
                pixel = _mm_xor_si128(pixel, auxp);                     // ((topaste || mask) | (background && mask))
                
                *bgPointer++ = pixel;
            }
       }
   }
}

void SGE_PasteSurface (SGE_Surface* background, const SGE_Surface* topaste, SGE_Rectangle position) 
{
    SGE_PasteSurfaceWithMask(background, topaste, NULL, position);
}

void SGE_PasteSurfaceWithMask (SGE_Surface* background, const SGE_Surface* topaste, const SGE_Surface* mask, SGE_Rectangle position)
{
    SGE_CpuInfo cpuid = SGE_GetCpuInfo();
    
    // Redimensionamos la imagen si es necesario
    SGE_Surface topaste2;
    if (topaste->imgData->height != position.height || topaste->imgData->width != position.width)
    {
        topaste2 = SGE_CloneSurface(topaste);
        SGE_ResizeSurface(&topaste2, position.width, position.height);
    }
    
    // Llamamos a la funcion privada correspondiente en orden de set de instrucciones,
    // del mas rapido al mas lento.
    if (cpuid.SSE2 && &topaste2 == NULL)
    {
        SGE_PasteSurfaceWithMaskSSE2 (background, topaste, mask, position);
    }
    else if (cpuid.SSE2 && &topaste2 != NULL)
    {
        SGE_PasteSurfaceWithMaskSSE2 (background, &topaste2, mask, position);
    }
    else if (cpuid.MMX && &topaste2 == NULL)
    {
        SGE_PasteSurfaceWithMaskMMX (background, topaste, mask, position);
    }
    else if (cpuid.MMX && &topaste2 != NULL)
    {
        SGE_PasteSurfaceWithMaskMMX (background, &topaste2, mask, position);
    }
    else
    {
        // TODO: Funcion compatible para todos los PC's
    }
        
    if (&topaste2 != NULL)
        SGE_FreeSurface(&topaste2);
}

#pragma region Funciones de tiempo

#ifdef _WIN32
#include "timer/sge_timer_windows.h"
#elif __unix__
#include "timer/sge_timer_unix.h"
#else
#error Plataforma no soportada
#endif

unsigned long SGE_GetTicks ()
{
#ifdef _WIN32
    return SGE_GetTicksWindows();
#elif __unix__
    return SGE_GetTicksUnix();
#endif
}

void SGE_Delay (unsigned long ms)
{
#ifdef _WIN32
    SGE_DelayWindows(ms);
#elif __unix__
    SGE_DelayUnix(ms);
#endif
}