#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector1() {
    vector v = createVector(0);

    pushBack(&v, 1);

    assert(v.data[1] == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);

    clear(&v);
}

void test_pushBack_emptyVector2() {
    vector v = createVector(3);

    pushBack(&v, 3);

    assert(v.data[1] == 3);
    assert(v.size == 1);
    assert(v.capacity == 3);

    clear(&v);
}

void test_pushBack_emptyVector() {
    test_pushBack_emptyVector1();
    test_pushBack_emptyVector2();
}

void test_pushBac_fullVector() {
    vector v = createVector(1);

    pushBack(&v, 5);
    pushBack(&v, 1);
    pushBack(&v, 7);

    assert(v.data[1] == 5);
    assert(v.data[2] == 1);
    assert(v.data[3] == 7);
    assert(v.size == 3);
    assert(v.capacity == 4);

    clear(&v);
}

void test_popBack_NonEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    clear(&v);
}

void test_atVector_nonEmptyVector() {
    vector v = createVector(10);
    pushBack(&v, 5);
    pushBack(&v, 3);

    int *k = atVector(&v, 0);
    assert (k == &v.data[0]);

    clear(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(1);
    pushBack(&v, 4);

    int *k = atVector(&v, 0);
    assert(k == &v.data[0]);

    clear(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 3);

    assert (back(&v) == &v.data[0]);

    clear(&v);
}

void test_front_oneElementInArray() {
    vector v = createVector(1);
    pushBack(&v, -3);

    assert(front(&v) == &v.data[0]);

    clear(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBac_fullVector();
    test_popBack_NonEmptyVector();
    test_atVector_nonEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInArray();
}

int main() {

    test();

    return 0;
}