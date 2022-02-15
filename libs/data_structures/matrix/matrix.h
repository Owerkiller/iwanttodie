#ifndef _COURSE__MATRIX_H
#define _COURSE__MATRIX_H

#include <malloc.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix  *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix (matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices (matrix *ms, int nMatrices);

void outputMatrix( matrix m);

void outputMatrices(matrix* ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int i1, int i2);



#endif //_COURSE__MATRIX_H
