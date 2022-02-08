#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _COURSE__VECTOR_H
#define _COURSE__VECTOR_H

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector ;

//Возвращает структуру-дискриптор вектор из n значений, если ОС не может предоставить память для создания вектора -
//вывод ошибки с кодом '0'
vector createVector(size_t n);

//Изменяет вместимость вектора v на значение newCapacity, если ОС не может предоставить память для создания вектора -
//вывод ошибки с кодом '0'
void reserve (vector *v, size_t newCapacity);

//Удаляет элементы из контейнера вектора v, но не освобождает выделенную память
void clear (vector *v);

//освобождает память, выделенную под неиспользованные элементы вектора v
void shrinkToFit (vector *v);

//Освобождает память, выделенную под вектор v
void deleteVector (vector *v);
#endif //_COURSE__VECTOR_H
