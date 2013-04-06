/* 
 * Funciones de tiempo para Windows
 */

#ifdef _WIN32
#ifndef SGE_TIMER_WINDOWS_H
#define	SGE_TIMER_WINDOWS_H

unsigned long SGE_GetTicksWindows ();

void SGE_DelayWindows (unsigned long ms);

#endif	/* SGE_TIMER_WINDOWS_H */
#endif