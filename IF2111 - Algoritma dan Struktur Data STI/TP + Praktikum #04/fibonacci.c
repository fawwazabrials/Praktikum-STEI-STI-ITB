/* File: fibonacci.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 25 September 2022
    Topik praktikum     : Prapraktikum #04 - Array dan ADT List
    Deskripsi           : Realisasi dari fibonacci.h
*/

#include "fibonacci.h"
#include <stdlib.h>

void fibonacci1(int n, int *result) {
// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8

    // KAMUS LOKAL
    
    // ALGORITMA
    *result = fibonacci2(n);
}

int fibonacci2(int n) {
// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
    // KAMUS LOKAL

    // ALGORITMA
    if (n < 2) return 1;
    return fibonacci2(n-2) + fibonacci2(n-1);
}

void fibonacci3(int n, int *result) {
// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    for (i=0; i<=n; i++) {
        *(result+i) = fibonacci2(i);
    }
}