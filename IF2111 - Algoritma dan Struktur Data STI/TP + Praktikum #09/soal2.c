/* File : soal2.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 4 November 2022
 * Topik Praktikum  : Pra-Praktikum 9 - List Linier
 * Deskripsi        : Menerapkan fungsi primitif list linier dengan
 *                    mengolah nilai-nilai mata kuliah.
 */

#include "listlinier.h"
#include <stdio.h>

int main() {
    // KAMUS LOKAL
    int in;
    List L;

    // KAMUS LOKAL
    CreateEmpty(&L);
    scanf("%d", &in);
    while (in <= 100 && in >= 0) {
        InsVLast(&L, in);
        scanf("%d", &in);
    }

    if (NbElmt(L) == 0) printf("Daftar nilai kosong\n");
    else {
        printf("%d\n%d\n%d\n%.2f\n", NbElmt(L), Max(L), Min(L), Average(L));
        PrintInfo(L); printf("\n");
        InversList(&L);
        PrintInfo(L); printf("\n");
    }

}