/* bilangan.c */

/* NIM              : 18221067 */
/* Nama             : Fawwaz Abrial Saffa */
/* Tanggal          : 9 September 2022 */
/* Topik Praktikum  : Praktikum 2 - Pengenalan C 2.0 */
/* Deskripsi        : Program menghitung jumlah total bilangan cantik */

#include <stdio.h>

int find7 (int angka) {
	int temp = angka;
	while (angka > 0) {
		if (angka % 10 == 7) return temp;
		angka /= 10;
	} return 0;
}

int main() {
    int n, in, ans, i;

    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d", &in);
        ans = 0;
        for (i=1; i<=in; i++) {
            if (i % 7 == 0) ans += i;
            else ans += find7(i);
        }
        printf("%d\n", ans);
    }

    return 0;
}