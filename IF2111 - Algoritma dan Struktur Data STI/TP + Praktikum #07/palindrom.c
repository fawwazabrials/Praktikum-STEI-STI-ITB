/* File : palindrom.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 Oktober 2022
    Topik praktikum     : Pra-praktikum #07 - Stack
    Deskripsi           : Mengecek apakah masukan berupa bilangan palindrom menggunakan stack
*/

#include "stack.h"
#include <stdio.h>

int main() {
    // KAMUS UTAMA
    Stack S;
    int len = 0, val, i;
    boolean found;

    // ALGORITMA
    CreateEmpty(&S);
    scanf("%d", &val);
    while (val != 0) {
        len++;
        Push(&S, val);
        scanf("%d", &val);
    }

    for (i = 0; i < len/2; i++) {
        Pop(&S, &val);
        if (S.T[i] != val) found = true;
    }

    if (len == 0) printf("Stack kosong\n");
    else {
        if (found) printf("Bukan Palindrom\n");
        else printf("Palindrom\n");
    }

    return 0;
}