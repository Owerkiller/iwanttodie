#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#ifndef _COURSE__VECTOR_H
#define _COURSE__VECTOR_H

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

//Возвращает структуру-дискриптор вектор из n значений, если ОС не может предоставить память для создания вектора -
//вывод ошибки с кодом '0'
vector createVector(size_t n);

//Изменяет вместимость вектора v на значение newCapacity, если ОС не может предоставить память для создания вектора -
//вывод ошибки с кодом '0'
void reserve(vector *v, size_t newCapacity);

//Удаляет элементы из контейнера вектора v, но не освобождает выделенную память
void clear(vector *v);

//освобождает память, выделенную под неиспользованные элементы вектора v
void shrinkToFit(vector *v);

//Освобождает память, выделенную под вектор v
void deleteVector(vector *v);

//Возвращает 'истина', если вектор v пуст (в нём нет полезных элементов, т.е. size = 0), в противном случае - 'ложь'
bool isEmpty(vector *v);

//Возвращает 'истина', если вектор v полон (используется вся доступная вместимость, т.е. size = capacity), в противном
// случае 'ложь'
bool isFull(vector *v);

//Возвращает i-тый элемент вектора v
int getVectorValue(vector *v, size_t i);

//Добавляет элемент x в конце вектора v. Если вектор заполнен, то увеличивает v.capacity в 2 раза
void pushBack(vector *v, int x);

//Удаляет последний элемент из вектора v. Если вектор v пуст - вывод ошибки с кодом "2"
void popBack(vector *v);

//Возвращает указатель на index-ный элемент вектора v. Если index > v.size - вывод ошибки
int* atVector (vector *v, size_t index);

//Возвращает указатель на последний элемент вектора v. Если вектор v пуст - вывод ошибки
int* back(vector *v);

//Возвращает указатель на нулевой элемент вектора v. Если вектор v пуст - вывод ошибки
int* front(vector *v);

#endif //_COURSE__VECTOR_H
