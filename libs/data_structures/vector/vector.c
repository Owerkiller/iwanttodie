#include <malloc.h>
#include "vector.h"

vector createVector(size_t n) {
    int *a;
    if (n) {
        a = (int *) malloc(sizeof(int) * n);
        if (a == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else
        a = NULL;

    return (vector) {a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        v->data= (int *) realloc(v->data, sizeof (int) * newCapacity);
        if (v->data == NULL){
            fprintf(stderr, "bad alloc");
            exit (1);
        }
    }
v->capacity=newCapacity;
    if (v->capacity < v->size)
        v->size = v->capacity;
}

void clearVector(vector *v){
    v->size = 0;
}

void ShrinkToFit(vector *v){
    reserve(v, v->size);
}

void clearVector(vector *v){
    v->data=NULL;
    v->size=0;
    v->capacity=0;
}