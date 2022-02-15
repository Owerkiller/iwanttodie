#include "matrix.h"
#include <stdio.h>
#include "../../algorithms/algorithms.h"
#include <assert.h>
#include <string.h>

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

    swap(m.values[i1], m.values[i2]);
}

void swapColumns(matrix m, int i1, int i2) {
    ifIndexOutOfSizeArray(m.nCols, i1);
    ifIndexOutOfSizeArray(m.nRows, i2);

    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][i1], &m.values[i][i2]);
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int rowCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 0; i < m.nRows; i++)
        for (int j = i; j > 0 && rowCriteria[j - 1]; j--) {
            swap(&rowCriteria[j - 1], &rowCriteria[i]);
            swapRows(m, j, j - 1);
        }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int colsCriteria[m.nCols];
    for (int j = 0; j < m.nCols; j++) {
        int colsElements[m.nRows];
        for (int i = 0; i < m.nRows; i++)
            colsElements[i] = m.values[i][j];

        colsCriteria[j] = criteria(colsElements, m.nRows);
    }

    for (int i = 1; i < m.nCols; i++)
        for (int j = i; j > 0 && colsCriteria[j - 1] > colsCriteria[j]; j--) {
            swap(&colsCriteria[j - 1], &colsCriteria[j]);
            swapColumns(m, j, j - 1);
        }
}

bool isSquareMatrix(matrix m) {
    return m.nRows = m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    bool isEqual = m1.nRows == m2.nRows && m1.nCols == m2.nCols;

    for (int i = 0; i < m1.nRows && isEqual; i++)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            isEqual = false;

    return isEqual;
}

bool isEMatrix(matrix m) {
    bool isEMatrix = isSquareMatrix(m);

    for (int i = 0; i < m.nRows && isEMatrix; i++)
        for (int j = 0; j < m.nCols; j++)
            if (i != j && m.values[i][j] != 0 || i == j && m.values[i][j] != 1)
                isEMatrix = false;

    return isEMatrix;
}

bool isSymmetricMatrix(matrix m) {
    bool isSymmetric = isSquareMatrix(m);

    for (int i = 0; i < m.nRows && isSymmetric; i++)
        for (int j = 0; j < i; j++)
            if (m.values[i][j] != m.values[j][i])
                isSymmetric = false;

    return isSymmetric;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "it isn't square matrix");
        exit(69);
    }

    for (int i = 0; i < m.nRows; i++)
        for (int j = i; j < m.nCols; j++)
            swap(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    position p;
    p.colIndex = 0;
    p.rowIndex = 0;
    int min = m.values[0][0];

    for (int i = 1; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                p.colIndex = j;
                p.rowIndex = i;
            }
    return (position) {p.rowIndex, p.colIndex};
}

position getMaxValuePos(matrix m) {
    position p;
    p.colIndex = 0;
    p.rowIndex = 0;
    int max = m.values[0][0];

    for (int i = 1; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                p.colIndex = j;
                p.rowIndex = i;
            }
    return (position) {p.rowIndex, p.colIndex};
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray ( const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}