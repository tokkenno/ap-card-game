#ifndef CPUID_H
#define	CPUID_H

typedef struct {
    int x64;
    int MMX;
    int SSE;
    int SSE2;
    int SSE3;
    int SSSE3;
    int SSE41;
    int SSE42;
    int SSE4a;
    int AVX;
    int XOP;
    int FMA3;
    int FMA4;
} cpu_info;

#ifdef _WIN32

#define cpuid __cpuid

#else

// Funcion cpuid para el compilador GCC
void cpuid(int CPUInfo[4],int InfoType);

#endif

// Obtiene informacion acerca de la CPU
cpu_info get_cpu_info();

#endif	/* CPUID_H */

