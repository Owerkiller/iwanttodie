#include <malloc.h>
#include "vector.h"

void _exitIfError(int *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector createVector(size_t n) {
    int *a;
    if (n) {
        a = (int *) malloc(sizeof(int) * n);
        _exitIfError(a);
    } else
        a = NULL;

    return (vector) {a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        _exitIfError(v->data);
    }
    v->capacity = newCapacity;
    if (v->capacity < v->size)
        v->size = v->capacity;
}

void clear(vector *v) {
    v->size = 0;
}

void ShrinkToFit(vector *v) {
    reserve(v, v->size);
}

void clearVector(vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return (v->size != 0);
}

bool isFull(vector *v) {
    return (v->size == v->capacity);
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);

    if (v->size == v->capacity)
        reserve(v, 2 * v->capacity);

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "haven't elements in array");
        exit(1);
    } else
        v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(322);
    } else
        return v->data + index;
}

int *back(vector *v) {
    _exitIfError(v->data);

    return v->data + v->size - 1;
}

int *front(vector *v) {
    _exitIfError(v->data);

    return v->data;
}