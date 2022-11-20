/* File : aritmatika.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 Oktober 2022
    Topik praktikum     : Pra-praktikum #07 - Stack
    Deskripsi           : Realisasi dari aritmatika.h
*/

#include "aritmatika.h"
#include <stdio.h>

boolean isOperator(char input) {
    // KAMUS LOKAL

    // ALGORITMA
    return ((input == '+') || (input == '-') || (input == '*') || (input == '/'));
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op) {
    // KAMUS LOKAL

    // ALGORITMA
    if (op == '+') return angka1 + angka2;
    else if (op == '-') return angka1 - angka2;
    else if (op == '*') return angka1 * angka2;
    else if (op == '/') return angka1 / angka2;
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length) {
    // KAMUS LOKAL
    Stack S;
    int i, val1, val2;

    // ALGORITMA
    CreateEmpty(&S);
    for (i = 0; i < length; i++) {
        if (isOperator(input[i])) {
            Pop(&S, &val2);
            Pop(&S, &val1);
            Push(&S, hitung(val1, val2, input[i]));
        } else {
            Push(&S, (input[i] - '0'));
        }
    }

    return InfoTop(S);
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/