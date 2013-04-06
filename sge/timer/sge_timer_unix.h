/* 
 * Funciones de tiempo para Unix
 */

#ifdef __unix__
#ifndef SGE_TIMER_UNIX_H
#define	SGE_TIMER_UNIX_H

unsigned long SGE_GetTicksUnix ();

void SGE_DelayUnix (unsigned long ms);

#endif	/* SGE_TIMER_UNIX_H */
#endif
