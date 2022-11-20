/* reverse.c */

/* NIM              : 18221067 */
/* Nama             : Fawwaz Abrial Saffa */
/* Tanggal          : 9 September 2022 */
/* Topik Praktikum  : Praktikum 2 - Pengenalan C 2.0 */
/* Deskripsi        : Program membalikkan sebuah angka */

#include <stdio.h>

int main() {
    long long int n, ans=0;

    scanf("%ld", &n);
    while (n > 0) {
        ans *= 10;
        ans += n%10;
        n /= 10;
    }

    printf("%ld\n", ans);
    return 0;
}