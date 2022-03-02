#ifndef _COURSE__STRING__H
#define _COURSE__STRING__H

#include <ctype.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct WordDescriptor WordDescriptor;
char stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *begin);

int getWord (char * beginSearch , WordDescriptor * word);

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

#endif
