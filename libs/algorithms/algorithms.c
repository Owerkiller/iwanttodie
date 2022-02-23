#include "algorithms.h"

void swap(int *a, int *b) {
    int k =  *a;
    *a = *b;
    *b = k;
}

void swapF(float *a, float *b){
    int k = *a;
    *a = *b;
    *b = k;
}
int split(int *a, const int left, const int right, const int pivot) {
    int i = left;
    int j = right;
    while (i < j) {
        while (a[i] < pivot)
            i++;
        while (a[j] < pivot)
            j--;
        if (i >= j)
            return j;
        swap(&a[i++], &a[j--]);
    }
    return j;
}

void _quicksort(int *a, const int left, const int right) {
    if (left < right) {
        int pivot = a[left + (right - left / 2)];
        int q = split(a, left, right, pivot);
        _quicksort(a, left, q - 1);
        _quicksort(a, q + 1, right);
    }
}

void quicksort(int *a, const int n) {
    _quicksort(a, 0, n - 1);
}