#include "libs/data_structures//matrix/matrix.h"
#include "libs/algorithms/algorithms.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

//////////////////////---task 1---//////////////////////////////////////////////////////////////////////////////////////
void swapRowsWithMinAndMaxElem(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);

    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

/////////////////////////---tests task 1---/////////////////////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////---task 2---/////////////////////////////////////////////////////////////
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

///////////////////////////////////////---test task 2---////////////////////////////////////////////////////////////////
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

//////////////////////////////////---task 3---//////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////---tests task 3---//////////////////////////////////////////////////////////////////
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
            3, 4);
    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12
            },
            3, 4);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_nonSquareMatrix1();
    test_sortColsByMinElement_nonSquareMatrix2();
    test_sortColsByMinElement_squareMatrix();
}

//////////////////////////////////////////---task 4---//////////////////////////////////////////////////////////////////
matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "number of row and number of columns are different");
        exit(420);
    }

    matrix product = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            product.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                product.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return (matrix) product;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}


///////////////////////////////////////--- test task 4---///////////////////////////////////////////////////////////////
void test_getSquareOfMatrixIfSymmetric_squareMatrix1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    2, 4, 3,
                    1, 3, 5
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    14, 17, 14,
                    17, 29, 29,
                    14, 29, 35
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));
}

void test_getSquareOfMatrixIfSymmetric_squareMatrix2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 5, 7,
                    5, 3, 3,
                    7, 3, 1
            },
            3, 3);
    getSquareOfMatrixIfSymmetric(&m1);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    75, 41, 29,
                    41, 43, 47,
                    29, 47, 59
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_squareMatrix1();
    test_getSquareOfMatrixIfSymmetric_squareMatrix2();
}
//////////////////////////////////////////////////////---task 5---//////////////////////////////////////////////////////
bool isUnique(long long *a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[i] == a[j])
                return false;
    }
    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(a, m.nRows))
        transposeSquareMatrix(m);
}


/////////////////////////////////////---test task 5---//////////////////////////////////////////////////////////////////

void test_transposeIfMatrixHasNotEqualSumOfRows_MatrixHaveUniqeSumElemOfRows() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9},
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[])
                    {1, 4, 7,
                     2, 5, 8,
                     3, 6, 9},
            3, 3
    );
    assert(isTwoMatricesEqual(m1, m2));
}

void test_transposeIfMatrixHasNotEqualSumOfRows_MatrixHaveNotUniqeSumElemOfRows() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {1, 2, 3,
                     2, 0, 4,
                     7, 8, 9},
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);


    matrix m2 = createMatrixFromArray(
            (int[])
                    {1, 2, 3,
                     2, 0, 4,
                     7, 8, 9},
            3, 3
    );
    assert(isTwoMatricesEqual(m1, m2));

}


void test_transposeIfMatrixHasNotEqualSumOfRows_MatrixFromOneElement() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {1},
            1, 1
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {1},
            1, 1
    );
    assert(isTwoMatricesEqual(m1, m2));
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_MatrixHaveUniqeSumElemOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows_MatrixHaveNotUniqeSumElemOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows_MatrixFromOneElement();
}
/////////////////////////////////////////---task 6---///////////////////////////////////////////////////////////////////
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {

    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    getMemMatrix(m1.nRows, m1.nCols);
    matrix m = getMemMatrix(m1.nRows, m1.nCols);
    m.nRows = m1.nRows;
    m.nCols = m1.nCols;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    bool isInverse = isEMatrix(m);
    freeMemMatrix(m);
    return isInverse;
}

/////////////////////////////////////////---test task 6---//////////////////////////////////////////////////////////////

void test_isMutuallyInverseMatrices_ItsTrue() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {2, 5, 7,
                     6, 3, 4,
                     5, -2, -3},
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[])
                    {1, -1, 1,
                     -38, 41, -34,
                     27, -29, 24},
            3, 3
    );

    assert(isMutuallyInverseMatrices(m1, m2) == true);
}

void test_isMutuallyInverseMatrices_ItsFalse() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {2, 5, 7,
                     6, 3, 4,
                     5, -2, -3},
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[])
                    {1, -1, 1,
                     -38, 0, -34,
                     27, -29, 24},
            3, 3
    );

    assert(isMutuallyInverseMatrices(m1, m2) == false);
}


void test_isMutuallyInverseMatrices_NonSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[])
                    {1, 2,
                     3, 4,
                     5, 6},
            3, 2
    );

    matrix m2 = createMatrixFromArray(
            (int[])
                    {3, 4,
                     5, 6,
                     3, 2},
            3, 2
    );

    assert(isMutuallyInverseMatrices(m1, m2) == false);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_ItsFalse();
    test_isMutuallyInverseMatrices_ItsTrue();
    test_isMutuallyInverseMatrices_NonSquareMatrix();
}

//////////////////////////////////////---task 7---//////////////////////////////////////////////////////////////////////

int max(int a, int b) {
    if (a > b)
        return a;

    return b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int size = m.nRows + m.nCols - 1;
    int elemPseudoDiagonal[size];

    for (int i = 0; i < size; i++)
        elemPseudoDiagonal[i] = INT_MIN;

    elemPseudoDiagonal[m.nRows - 1] = 0; // лежал мусор

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                int k = j - i + m.nRows - 1;
                elemPseudoDiagonal[k] = max(elemPseudoDiagonal[k], m.values[i][j]);
            }

    return getSum(elemPseudoDiagonal, size);
}////////////////////////////////////////---tests task 7---///////////////////////////////////////////////////////////////

void test_findSumOfMaxesOfPseudoDiagonal_positiveMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 7, 9,
                    2, 6, 2, 1,
                    3, 5, 6, 7,
                    4, 2, 1, 6
            },
            4, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 35);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -1, -3, -2, -5,
                    -4, -1, -3, -1,
                    -9, -5, -2, -4,
                    -7, -3, -4, -5
            },
            4, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -23);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveAndNegativeElemInMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -4, 2, -1, 0,
                    4, 7, -2, 1,
                    -3, -5, 5, 3,
                    -3, -1, -5, -21
            },
            4, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 4);
    freeMemMatrix(m1);
}


void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_positiveMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveAndNegativeElemInMatrix();
}


///////////////////////////////---task 8---/////////////////////////////////////////////////////////////////////////////
int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int getMinInArea(matrix m) {
    position minElemPos = getMaxValuePos(m);
    int minElem = m.values[minElemPos.rowIndex][minElemPos.colIndex];

    int jRight = minElemPos.colIndex;
    int jLeft = minElemPos.colIndex;

    for (int i = minElemPos.rowIndex - 1; i >= 0; i--) {
        if (jLeft > 0)
            jLeft--;

        if (jRight < m.nCols)
            jRight++;

        minElem = min(getMin(&m.values[i][jLeft], jRight - jLeft), minElem);
    }

    return minElem;
}

////////////////////////////////////////////---tests task 8---//////////////////////////////////////////////////////////
void test_getMinInArea_minInFirstRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 1, 3,
                    4, 9, 2,
                    0, 3, 2},
            3, 3

    );
    assert(getMinInArea(m) == 1);
}

void test_getMinInArea_minInNonFirstRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 1, 3, 4,
                    4, 9, 2, 7,
                    0, 3, 2, 19,
                    15, 0, 7, 5},
            4, 4

    );
    assert(getMinInArea(m) == 1);
}

void test_getMinInArea_matrixFromOneElem() {
    matrix
            m = createMatrixFromArray(
            (
                    int[]) {
                    3
            },
            1, 1
    );
    assert(getMinInArea(m) == 3);
}

void test_getMinInArea_matrixInOneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
                    2,
                    3,
                    5
            },
            4, 1
    );
    assert(getMinInArea(m) == 1);
}

void test_getMinInArea__matrixInOneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 4, 9, 5
            },
            1, 4
    );
    assert(getMinInArea(m) == 9);
}

void test_getMinInArea() {
    test_getMinInArea_minInFirstRow();
    test_getMinInArea_minInNonFirstRow();
    test_getMinInArea_matrixFromOneElem();
    test_getMinInArea_matrixInOneRow();
    test_getMinInArea__matrixInOneCol();
}

////////////////////////////////////////////---task 9---////////////////////////////////////////////////////////////////

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    distance = sqrtf(distance);
    return distance;
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float rowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++)
        for (int j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swapF(&rowsCriteria[j - 1], &rowsCriteria[j]);
            swapRows(m, j, j - 1);
        }
}

void sortByDistance(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

/////////////////////////////////////////////---test task 9---/////////////////////////////////////////////////////////

void test_sortByDistance_RandomPoints() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 6,//7
                    3, 4, 0,//5
                    6, 8, 0//10
            },
            3, 3
    );

    sortByDistance(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 4, 0,
                    3, 2, 6,
                    6, 8, 0
            },
            3, 3
    );
    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortByDistance_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );

    sortByDistance(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );
    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortByDistance_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 5, 6
            },
            1, 4
    );

    sortByDistance(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 3, 5, 6
            },
            1, 4
    );
    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortByDistance_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,
                    5,
                    3,
                    7
            },
            4, 1
    );

    sortByDistance(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1,
                    3,
                    5,
                    7
            },
            4, 1
    );
    assert(isTwoMatricesEqual(m1, m2));
}

void test_sortByDistance() {
    test_sortByDistance_RandomPoints();
    test_sortByDistance_oneElem();
    test_sortByDistance_oneRow();
    test_sortByDistance_oneCol();
}

///////////////////////////////////---task 10---/////////////////////////////////////////////////////////////////////////
int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);
    int counter = 1;
    int i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counter++;
        i++;
    }

    return counter;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowSums[i] = getSum(m.values[i], m.nCols);

    return countNUnique(rowSums, m.nRows);
}

///////////////////////////////////////////---test task 10----//////////////////////////////////////////////////////////
void test_countEqClassesByRowsSum_MatrixWithOnlyDifferentRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    assert(countEqClassesByRowsSum(m) == 3);
}

void test_countEqClassesByRowsSum_MatrixWithEqualSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 0,
                    -1, 4
            },
            3, 2
    );

    assert(countEqClassesByRowsSum(m) == 1);
}

void test_countEqClassesByRowsSum_MatrixFromOneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );

    assert(countEqClassesByRowsSum(m) == 1);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_MatrixWithOnlyDifferentRowsSum();
    test_countEqClassesByRowsSum_MatrixWithEqualSum();
    test_countEqClassesByRowsSum_MatrixFromOneElem();
}

//////////////////////////////////---task 11---/////////////////////////////////////////////////////////////////////////

int getNSpecialElement(matrix m) {
    int countSpecialElems = 0;
    for (int j = 0; j < m.nCols; j++) {
        int specialElem = m.values[0][j];
        int sumOfCol = 0;
        for (int i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElem) {
                sumOfCol += specialElem;
                specialElem = m.values[i][j];
            } else
                sumOfCol += m.values[i][j];
        }
        if (specialElem > sumOfCol)
            countSpecialElems++;
    }
    return countSpecialElems;
}

////////////////////////////////////////////////////---test task 11---//////////////////////////////////////////////////

void test_getNSpecialElement_matrixWithSpecialElems() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    15, 100, 3,
                    10, 7, 95,
                    1, 6, 3
            },
            3, 3
    );

    assert(getNSpecialElement(m) == 3);
}

void test_getNSpecialElement_matrixWithoutSpecialElems() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    8, 10, 3,
                    10, 7, 4,
                    5, 6, 3
            },
            3, 3
    );

    assert(getNSpecialElement(m) == 0);
}

void test_getNSpecialElement_matrixFromOneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );

    assert(getNSpecialElement(m) == 1);
}


void test_getNSpecialElement() {
    test_getNSpecialElement_matrixWithSpecialElems();
    test_getNSpecialElement_matrixWithoutSpecialElems();
    test_getNSpecialElement_matrixFromOneElem();
}


///////////////////////////////////////////---task 12---////////////////////////////////////////////////////////////////
position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPos = {0, 0};

    for (int i = 0; i < m.nCols; i++)
        for (int j = 0; j < m.nRows; j++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }

    return minPos;
}

void swapPenultimateRow(matrix m, int n) { //зачем тут n?
    if (m.nRows < 2) {
        fprintf(stderr, "can't swap");
        exit(228);
    }

    position min = getLeftMin(m);

    int col[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        col[i] = m.values[i][min.colIndex];

    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

///////////////////////////////////////---test task 12---///////////////////////////////////////////////////////////////

void test_swapPenultimateRow_squareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    swapPenultimateRow(m1, 0);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 9
            },
            3, 3
    );

    assert(isTwoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_squareMatrix();
}


///////////////////////////////////////////---task 13---////////////////////////////////////////////////////////////////


//////////////////////////////////////main//////////////////////////////////////////////////////////////////////////////
int main() {
    //test_swapRowsWithMinAndMaxElem_maxAndMinInSameRow();
    //test_swapRowsWithMinAndMaxElem_maxAndMinInDifferentRows();

    //test_sortRowsByMinElements();

    //test_sortColsByMinElement();

    //test_getSquareOfMatrixIfSymmetric();

    //test_transposeIfMatrixHasNotEqualSumOfRows();

    //test_isMutuallyInverseMatrices();

    //test_findSumOfMaxesOfPseudoDiagonal();

    //test_getMinInArea();

    //test_sortByDistance();

    test_countEqClassesByRowsSum();

    test_getNSpecialElement();

    test_swapPenultimateRow();

    return 0;
}