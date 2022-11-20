/* File: hitungkarakter.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 September 2022
    Topik praktikum     : Prapraktikum #05 - Mesin kata & karakter
    Deskripsi           : Program untuk menghitung jumlah karakter yang muncul menggunakan mesin karakter
*/

#include <stdio.h>
#include "mesinkarakter.h"

int hitungkarakter(char karakter) {
    // KAMUS LOKAL
    int len;

    // ALGORITMA
    len = 0;
    START();
    while (!EOP) {
        if (GetCC() == karakter) len++;
        ADV();
    } return len;
}