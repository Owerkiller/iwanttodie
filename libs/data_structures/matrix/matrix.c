#include "matrix.h"
#include <stdio.h>
#include "../../algorithms/algorithms.h"
#include <assert.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
};

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix));
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nCols; i++)
        for (int j = 0; j < m.nRows; j++) {
            scanf("%d", &m.values[i][j]);
        }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void ifIndexOutOfSizeArray(int size, int index) {
    if (index >= size) {
        fprintf(stderr, "index %d out of range", index);
        exit(2);
    }
}

void swapRows(matrix m, int i1, int i2) {
    ifIndexOutOfSizeArray(m.nRows, i1);
    ifIndexOutOfSizeArray(m.nCols, i2);

    swap(&m.values[i1], &m.values[i2]);
}

void swapColumns(matrix m, int i1, int i2) {
    ifIndexOutOfSizeArray(m.nCols, i1);
    ifIndexOutOfSizeArray(m.nRows, i2);

    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][i1], &m.values[i][i2]);
    }
}
