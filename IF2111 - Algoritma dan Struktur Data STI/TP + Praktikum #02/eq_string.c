/* NIM              : 18221067 */
/* Nama             : Fawwaz Abrial Saffa */
/* Tanggal          : 9 September 2022 */
/* Topik Praktikum  : Praktikum 2 - Pengenalan C 2.0 */
/* Deskripsi        : Program mencetak persegi dengan sisi 2n*1 
                        dengan pola 'X' dan 'O' berselang seling */

/* KAMUS */
/*  */
/*  */

/* ALGORITMA */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int ascii_1, ascii_2, isSame=1;
    char* str1; 
    char* str2;
    str1 = (char*) malloc (100*sizeof(char)); 
    str2 = (char*) malloc (100*sizeof(char));

    scanf("%s %s", str1, str2);

    if (strlen(str1) == strlen(str2)) {
        while (isSame && *str1!='\0' && *str2!='\0') {
            ascii_1 = *str1; ascii_2 = *str2;
            if (!(ascii_1 != ascii_2 || ascii_1 != (ascii_2+32) || ascii_1+32 != ascii_2)) {
                isSame = 0;
            }
            str1++; str2++;
        }
    } else {isSame=0;}
    

    if (isSame) {printf("Ya\n");}
    else {printf("Tidak\n");}

    return 0;
}