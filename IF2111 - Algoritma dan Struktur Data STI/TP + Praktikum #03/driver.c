#include <stdio.h>
#include "arraydin.h"

void printArray(ArrayDin array) {
    printf("Nilai effektif : %d\n", array.Neff);
    for (int i=0; i<Length(array); i++) {
        printf("%d ", array.A[i]);
    } printf("\n");
}

int main() {
    ArrayDin array;
    array = MakeArrayDin();
    /* printf("isEmpty = %u\n", IsEmpty(array)); */

    InsertAt(&array, 2, 0);
    InsertAt(&array, 5, 1);
    InsertAt(&array, 3, 2);
    InsertAt(&array, 7, 3);
    InsertAt(&array, 9, 4);
    InsertAt(&array, 9, 5);
    InsertAt(&array, 9, 6);
    InsertAt(&array, 9, 7);
    InsertAt(&array, 9, 8);
    InsertAt(&array, 9, 9);
    InsertAt(&array, 9, 10);
    InsertAt(&array, 9, 11);
    InsertAt(&array, 100, 4);

    printArray(array);

    DeallocateArrayDin(&array);

    printArray(array);
}