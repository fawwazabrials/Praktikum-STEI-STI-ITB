/* indeksalstrukdat.c */

/* NIM              : 18221067 */
/* Nama             : Fawwaz Abrial Saffa */
/* Tanggal          : 9 September 2022 */
/* Topik Praktikum  : Praktikum 2 - Pengenalan C 2.0 */
/* Deskripsi        : Program menghitung statistik dari nilai-nilai alstrukdat */

#include <stdio.h>

int main() {
    int nilai=0, len=0, lulus=0;
    float sum = 0;

    while (nilai != -999) {
        scanf("%d", &nilai);
        if (nilai >= 0 && nilai <= 4) {
            if (nilai >= 3) lulus++;
            len++;
            sum += nilai;
        }
    }

    if (len == 0) printf("Tidak ada data");
    else {
        sum /= len;
        printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
        printf("Nilai rata-rata = %.2f\n", sum);
        printf("Indeks akhir kelas = ");
        if (sum == 4.00) printf("A");
        else if (sum >= 3.00) printf("B");
        else if (sum >= 2.00) printf("C");
        else if (sum >= 1.00) printf("D");
        else if (sum >= 0.00) printf("E");
    } printf("\n");

    return 0;
}