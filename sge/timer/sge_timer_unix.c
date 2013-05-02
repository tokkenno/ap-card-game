
#ifdef __unix__
#include "sge_timer_unix.h"
#include "../sge_types.h"

#include <sys/time.h>

#if HAVE_CLOCK_GETTIME
#include <time.h>
#endif

static char start_i = 0;
#ifdef HAVE_CLOCK_GETTIME
static struct timespec start;
#else
static struct timeval start;
#endif

/*
 * Inicializa los registros
 */
void SGE_StartTicksUnix(void)
{
#if HAVE_CLOCK_GETTIME
    clock_gettime(CLOCK_MONOTONIC,&start);
#else
    gettimeofday(&start, NULL);
#endif
    start_i = 1;
}

unsigned long SGE_GetTicksUnix ()
{
    if (!start_i)
        SGE_StartTicksUnix();
    
#if HAVE_CLOCK_GETTIME
    unsigned long ticks;
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC,&now);
    ticks=(now.tv_sec-start.tv_sec)*1000+(now.tv_nsec-start.tv_nsec)/1000000;
    return(ticks);
#else
    unsigned long ticks;
    struct timeval now;
    gettimeofday(&now, NULL);
    ticks=(now.tv_sec-start.tv_sec)*1000+(now.tv_usec-start.tv_usec)/1000;
    return(ticks);
#endif
}

void SGE_DelayUnix (unsigned long ms)
{
    int was_error = 0;

    struct timeval tv;
    unsigned long then, now, elapsed;
    
    then = SGE_GetTicksUnix();
    
    do {
        now = SGE_GetTicksUnix();
        elapsed = (now-then);
        then = now;
        if ( elapsed >= ms ) {
            break;
        }
        ms -= elapsed;
        tv.tv_sec = ms/1000;
        tv.tv_usec = (ms%1000)*1000;

        was_error = select(0, NULL, NULL, NULL, &tv);
        
    } while (was_error);
}
#endif
