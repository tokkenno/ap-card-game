/*
 * Funciones que identifican caracteristicas de la CPU en tiempo de ejecucion,
 * como por ejemplo, el set de instrucciones soportadas.
 */

#ifndef CPUID_H
#define	CPUID_H

/**
 * Registro que contiene informacion acerca de las caracteristicas de una CPU
 */
typedef struct {
    int x64;    /**< Set de instrucciones AMD64 */
    int MMX;    /**< Set de instrucciones Intel MMX */
    int SSE;    /**< Set de instrucciones Intel SSE */
    int SSE2;   /**< Set de instrucciones Intel SSE2 */
    int SSE3;   /**< Set de instrucciones Intel SSE3 */
    int SSSE3;  /**< Set de instrucciones Intel SSE3S */
    int SSE41;  /**< Set de instrucciones Intel SSE4.1 */
    int SSE42;  /**< Set de instrucciones Intel SSE4.2 */
    int SSE4a;  /**< Set de instrucciones AMD SSE4.1a */
    int AVX;    /**< Set de instrucciones Intel AVX */
    int XOP;    /**< Set de instrucciones AMD XOP */
    int FMA3;   /**< Set de instrucciones FMA3 */
    int FMA4;   /**< Set de instrucciones FMA4 */
} SGE_CpuInfo;

/**
 * Obtiene informacion acerca de la CPU en tiempo de ejecucion
 * @return Registro con las caracteristicas de la CPU
 */
SGE_CpuInfo SGE_GetCpuInfo();

#endif	/* CPUID_H */

