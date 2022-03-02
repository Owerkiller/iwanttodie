#ifndef _COURSE__REMOVENONLETTERS_H
#define _COURSE__REMOVENONLETTERS_H


#include "../string_.h"
#include <ctype.h>


void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_stringWithoutSpaces(){
    char s[]="YaChelovek";
    removeNonLetters(s);
    ASSERT_STRING("YaChelovek", s);
}

void test_removeNonLetters_stringWithSpaces(){
    char s[] = "I love NY";
    removeNonLetters(s);
    ASSERT_STRING("IloveNY", s);
}

void test_removeNonLetters_emptyString(){
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("",s);
}

void test_removeNonLetters_specialSpaceSymbols(){
    char s[] = "\tI lo\nve\tNY  ";
    removeNonLetters(s);
    ASSERT_STRING("IloveNY", s);
}

void test_removeNonLetters(){
    test_removeNonLetters_stringWithoutSpaces();
    test_removeNonLetters_stringWithSpaces();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_specialSpaceSymbols();
}

#endif