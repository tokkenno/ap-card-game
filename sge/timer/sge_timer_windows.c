#ifdef _WIN32

#include "sge_timer_windows.h"
#include <windows.h>
#include <winbase.h>

static unsigned long _w_ticks;

unsigned long SGE_GetTicksWindows ()
{
    if (!_w_ticks)
        _w_ticks = GetTickCount();
    
    long ticks = _w_ticks;
    _w_ticks = GetTickCount();
    return _w_ticks - ticks;
}

void SGE_DelayWindows (unsigned long ms)
{
    Sleep(ms);
}

#endif