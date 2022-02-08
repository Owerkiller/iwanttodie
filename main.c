#include "libs/data_structures/vector/vector.h"

int main(){
    vector v = createVector(0);

    size_t newCapacity;
    scanf("%zu", &newCapacity);

    reserve(&v, newCapacity);

    return 0;
}