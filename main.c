#include "libs/data_structures//matrix/matrix.h"
#include <assert.h>
#include <stdio.h>

void swapRowsWithMinAndMaxElem(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);

    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

void test_swapRowsWithMinAndMaxElem_maxAndMinInDifferentRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3);
    swapRowsWithMinAndMaxElem(m1);

    matrix
            m2 = createMatrixFromArray((int[]) {
                                               7, 8, 9,
                                               4, 5, 6,
                                               1, 2, 3
                                       },
                                       3, 3);


    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapRowsWithMinAndMaxElem_maxAndMinInSameRow() {
    matrix m1 = createMatrixFromArray((int[]) {
                                              1, 100, 5,
                                              3, 14, 15,
                                              28, 39, 4
                                      },
                                      3, 3);

    swapRowsWithMinAndMaxElem(m1);

    matrix m2 = createMatrixFromArray((int[]) {
                                              1, 100, 5,
                                              3, 14, 15,
                                              28, 39, 4
                                      },
                                      3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMinElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);

}


void test_sortRowsByMinElements_squareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3
            },
            3, 3);
    sortRowsByMinElements(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElements_notSquareMatrix1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9, 12,
                    4, 5, 6, 9,
                    1, 2, 3, 6
            },
            3, 4);
    sortRowsByMinElements(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 6,
                    4, 5, 6, 9,
                    7, 8, 9, 12
            },
            3, 4);

    assert(isTwoMatricesEqual(m1, m2));
}


void test_sortRowsByMinElements_notSquareMatrix2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 1,
                    3, 1, 1,
                    1, 1, 2,
                    1, 1, 1
            },
            4, 3);
    sortRowsByMinElements(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 2,
                    3, 1, 1,
                    1, 4, 1
            },
            4, 3);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElements() {
    test_sortRowsByMinElements_squareMatrix();
    test_sortRowsByMinElements_notSquareMatrix1();
    test_sortRowsByMinElements_notSquareMatrix2();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement_squareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    3, 2, 1
            },
            3, 3);
    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    6, 5, 4,
                    1, 2, 3
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortColsByMinElement_nonSquareMatrix1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9, 4,
                    4, 5, 6, 5,
                    3, 2, 5, 8
            },
            3, 4);
    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    8, 7, 4, 9,
                    5, 4, 5, 6,
                    2, 3, 8, 5
            },
            3, 4);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortColsByMinElement_nonSquareMatrix2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 3, 2, 1,
                    8, 7, 6, 5,
                    12, 11, 10, 9
            },
            4, 3);
    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_nonSquareMatrix1();
    test_sortColsByMinElement_nonSquareMatrix2();
    test_sortColsByMinElement_squareMatrix();
}

int main() {
    test_swapRowsWithMinAndMaxElem_maxAndMinInSameRow();
    test_swapRowsWithMinAndMaxElem_maxAndMinInDifferentRows();

    test_sortRowsByMinElements();

    test_sortColsByMinElement();
    return 0;
}