/* File : OddEvenList.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 4 November 2022
 * Topik Praktikum  : Pra-Praktikum 9 - List Linier
 * Deskripsi        : Realisasi OddEvenList.h
 */

#include "OddEvenList.h"

/* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
/* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
/* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
        List L TIDAK PERLU DIDEALOKASI*/
/*Contoh:
    Input:
        L: [0,3,1,4,5]
        Odd: []
        Even: []
    Output:
        L: [0,3,1,4,5]
        Odd: [1,3,5]
        Even: [0,4] */
/*Note: 
    1. Bilangan 0 merupakan bilangan genap
    2. Buatlah List Odd dan Even terlebih dahulu*/
void OddEvenList(List L, List *Odd, List *Even) {
    // KAMUS LOKAL
    List genap, ganjil;
    address P;

    // ALGORITMA
    CreateEmpty(Odd); CreateEmpty(Even);
    CreateEmpty(&ganjil); CreateEmpty(&genap);
    P = First(L);
    while (P != Nil) {
        if (Info(P) % 2 == 0) InsVLast(&genap, Info(P));
        else InsVLast(&ganjil, Info(P));
        P = Next(P);
    }

    while (!IsEmpty(genap)) {
        InsVLast(Even, Min(genap));
        DelP(&genap, Min(genap));
    } while (!IsEmpty(ganjil)) {
        InsVLast(Odd, Min(ganjil));
        DelP(&ganjil, Min(ganjil));
    }
}
