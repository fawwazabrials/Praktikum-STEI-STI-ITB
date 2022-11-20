/* NIM              : 18221067 */
/* Nama             : Fawwaz Abrial Saffa */
/* Tanggal          : 9 September 2022 */
/* Topik Praktikum  : Praktikum 2 - Pengenalan C 2.0 */
/* Deskripsi        : Program mencetak persegi dengan sisi 2n*1 
                        dengan pola 'X' dan 'O' berselang seling */

/* KAMUS */
/* n, i : integer */
/* now : character */

/* ALGORITMA */
#include <stdio.h>

int main() {
    int i, j;
    long long int n;
    char huruf='O';
    scanf("%lld", &n);


    for(i = 0; i<2*n-1; i++) {
        for (j = 0; j<2*n-1; j++) {
            printf("%c", huruf);
            if (huruf == 'O') {
                huruf = 'X';
            }
            else {
                huruf = 'O';
            }
        } 
        printf("\n");
    }
    return 0;
}