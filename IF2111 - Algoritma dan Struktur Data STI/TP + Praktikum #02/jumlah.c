/* NIM              : 18221067 */
/* Nama             : Fawwaz Abrial Saffa */
/* Tanggal          : 9 September 2022 */
/* Topik Praktikum  : Praktikum 2 - Pengenalan C 2.0 */
/* Deskripsi        : Program untuk menghitung hasil penjumlahan dari semua digit pada sebuah angka*/

#include <stdio.h>
int main () {
    /* KAMUS */
    long long int n, sum=0;

    /* ALGORITMA */
    scanf("%ld", &n);
    while (n > 0) {
        sum += n%10;
        n/=10;
    } printf("%d\n", sum);
    return 0;
}

