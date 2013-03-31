#include "strhelper.h"

#include <stdlib.h>
#include <string.h>

char* strconcat (char* str1, char* str2)
{
    char* strc;
    
    strc = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(strc, str1);
    strcat(strc, str2);
    
    return strc;
}