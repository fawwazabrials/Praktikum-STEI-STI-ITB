/* File: reverse.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 Oktober 2022
    Topik praktikum     : Prapraktikum #06 - Queue
    Deskripsi           : Realisasi dari reverse.h
*/

#include "reverse.h"
#include <stdlib.h>
#include <stdio.h>

void transferReverse(Queue* q1, Queue* q2) {
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
    // KAMUS LOKAL
    ElType temp;
    int i, x;

    // ALGORITMA
    for (i = 0; i < Length(*q1); i++) {
        temp = Pop(q1);
        Push(q1, temp);
        Push(q2, temp);
    }

    for (i = 0; i < (Length(*q2)/2); i++) {

        x = (*q2).Tab[i];
        (*q2).Tab[i] = (*q2).Tab[(*q2).TAIL - i];
        (*q2).Tab[(*q2).TAIL - i] = x;
    }
}