#ifdef _WIN32

#include "sge_timer_windows.h"
#include <windows.h>

unsigned long SGE_GetTicksWindows ()
{
    
}

void SGE_DelayWindows (unsigned long ms)
{
    Sleep(ms);
}

#endif