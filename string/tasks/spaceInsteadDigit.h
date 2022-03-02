#ifndef _COURSE__SPACEINSTEADDIGIT_H
#define _COURSE__SPACEINSTEADDIGIT_H

#include "../string_.h"

void spaceInsteadDigit(char *s) {
    char *endOfString = getEndOfString(s);
    char *startOfBuffer = stringBuffer;
    char *endOfBuffer =  copy(s, endOfString, startBuffer);
    *endOfBuffer = '\0';

    while (*startOfBuffer != '\0'){
        if (isalpha(*startOfBuffer))
            *s++ = *startBuffer;
        else if (isdigit(*startBuffer)) {
            unsigned char a = *startBuffer - CODE_DIFFERENCE;
            while (a--)
                *s++ = ' ';
        }
        startBuffer++;
    }
    *s = '\0';
}

#endif
