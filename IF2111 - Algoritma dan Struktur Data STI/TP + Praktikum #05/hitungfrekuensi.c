/* File: hitungfrekuensi.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 September 2022
    Topik praktikum     : Praktikum #05 - Mesin kata & karakter
    Deskripsi           : Realisasi hitungfrekuensi.h
*/

#include <stdio.h>
#include "hitungfrekuensi.h"

int hitungfrekuensi() {
    // KAMUS LOKAL
    int cnt;

    // ALGORITMA
    cnt = 0;
    START();
    while (!EOP) {
        if (currentChar == 't' || currentChar == 'T') {
            ADV();
            if (currentChar == 'i' || currentChar == 'I') {
                ADV();
                if (currentChar == 'g' || currentChar == 'G') {
                    ADV();
                    if (currentChar == 'a' || currentChar == 'A') {
                        cnt++;
                        ADV();
                    }
                }
            }
        }
        else ADV();
    } return cnt;
}