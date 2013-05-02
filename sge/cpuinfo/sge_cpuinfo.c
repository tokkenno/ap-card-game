#include "sge_cpuinfo.h"

#ifdef _WIN32
#include <windows.h>
#define cpuid __cpuid
#else

void cpuid(int CPUInfo[4],int InfoType){
    __asm__ __volatile__ (
        "cpuid":
        "=a" (CPUInfo[0]),
        "=b" (CPUInfo[1]),
        "=c" (CPUInfo[2]),
        "=d" (CPUInfo[3]) :
        "a" (InfoType)
    );
}

#endif

SGE_CpuInfo SGE_GetCpuInfo() {
    SGE_CpuInfo toret;
    
    toret.MMX = toret.SSE = toret.SSE2 = toret.SSE3 = toret.SSSE3 = 0;
    toret.SSE41 =  toret.SSE42 =  toret.AVX = toret.FMA3 = 0;
    toret.SSE4a = toret.FMA4 = toret.XOP = toret.x64 = 0;
    
    int info[4];
    cpuid(info, 0);
    int nIds = info[0];

    cpuid(info, 0x80000000);
    int nExIds = info[0];

    if (nIds >= 1) {
        cpuid(info,0x00000001);
        toret.MMX   = (info[3] & ((int)1 << 23)) != 0;
        toret.SSE   = (info[3] & ((int)1 << 25)) != 0;
        toret.SSE2  = (info[3] & ((int)1 << 26)) != 0;
        toret.SSE3  = (info[2] & ((int)1 <<  0)) != 0;

        toret.SSSE3 = (info[2] & ((int)1 <<  9)) != 0;
        toret.SSE41 = (info[2] & ((int)1 << 19)) != 0;
        toret.SSE42 = (info[2] & ((int)1 << 20)) != 0;

        toret.AVX   = (info[2] & ((int)1 << 28)) != 0;
        toret.FMA3  = (info[2] & ((int)1 << 12)) != 0;
    }

    if (nExIds >= 0x80000001) {
        cpuid(info,0x80000001);
        toret.x64   = (info[3] & ((int)1 << 29)) != 0;
        toret.SSE4a = (info[2] & ((int)1 <<  6)) != 0;
        toret.FMA4  = (info[2] & ((int)1 << 16)) != 0;
        toret.XOP   = (info[2] & ((int)1 << 11)) != 0;
    }
    
    return toret;
}
