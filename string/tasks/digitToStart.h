#ifndef _COURSE__DIGITTOSTART_H
#define _COURSE__DIGITTOSTART_H

#include "../string_.h"
#include <ctype.h>

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char  *recPosition = copyIfReverse (endStringBuffer -1, stringBuffer - 1, word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartForAllString (char * s){
    char *start = s;
    WordDescriptor word;
    while ((getWord(start, &word))){
        digitToStart(word);
        start = word.end;
    }
}

void test_digitToStartForAllString_noWord(){}

void test_digitToStartForAllString_wordWithoutDigit(){}

void test_digitToStartForAllString_wordWithOneDigit(){}

void test_digitToStartForAllString_wordWithManyDigit(){}

void test_digitToStartForAllString(){
    test_digitToStartForAllString_noWord();
    test_digitToStartForAllString_wordWithoutDigit();
    test_digitToStartForAllString_wordWithOneDigit();
    test_digitToStartForAllString_wordWithManyDigit();
}

#endif
