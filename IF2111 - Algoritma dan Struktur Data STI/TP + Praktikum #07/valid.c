/* File : valid.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 24 Oktober 2022
    Topik praktikum     : Praktikum #07 - Stack
    Deskripsi           : Realisasi dari valid.h
*/

#include "valid.h"

Stack validParantheses(char* input, int length) {
    // KAMUS LOKAL
    Stack S;
    infotype val, temp=' ';
    int i;

    // ALGORITMA
    CreateEmpty(&S);
    for (i=0; i<length; i++) {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') temp = input[i];
        else if ((temp == '(' && input[i] == ')') || 
                 (temp == '[' && input[i] == ']') || 
                 (temp == '{' && input[i] == '}')) 
                {
            Push(&S, temp);
            Push(&S, input[i]);
            temp = ' ';
        }
    } return S;
}
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/