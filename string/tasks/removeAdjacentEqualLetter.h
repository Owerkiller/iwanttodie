#ifndef _COURSE__REMOVEADJACENTEQUALLETTER_H
#define _COURSE__REMOVEADJACENTEQUALLETTER_H

#include "../string_.h"

void removeAdjacentEqualLetter(char *s) {
    char *begin = s;
    char *dist = begin;
    char last = *begin;

    while (*begin != '\n') {
        if (*begin != last)
            *dist++ = *begin;

        last = *begin++;
    }

    *dist = '\0';
}

void test_removeAdjacentEqualLetter_emptyString(){
    char  s[]="";
    removeAdjacentEqualLetter(s);
    ASSERT_STRING("",s);
}

void test_removeAdjacentEqualLetter(){
    test_removeAdjacentEqualLetter_emptyString();
}

#endif
