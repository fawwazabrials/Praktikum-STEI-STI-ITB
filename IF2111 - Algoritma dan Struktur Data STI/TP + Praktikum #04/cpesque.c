/* FIle : cpesque.c */

/*  
 * NIM				: 18221067
 * Nama				: Fawwaz Abrial Saffa
 * Tanggal			: 26 September 2022
 * Topik praktikum	: Praktikum #04 - Array dan ADT List
 * Deskripsi 		: Diberikan suatu array dengan ukuran N. Anggaplah isi dari array tersebut diulang tak hingga kali. Kemudian, diberikan rentang l dan r sebanyak q kali, hitunglah penjumlahan bilangan dari posisi l sampai posisi ke r!
 */
 
#include <stdio.h>
 
int main() {
	// KAMUS
	long long int arr[1001], N, q, l, r, i, j, sum;
	
	// ALGORITMA
	scanf("%lld", &N);
	for (i=0; i<N; i++) {
		scanf("%lld", &arr[i]);
	}
	
	scanf("%lld", &q);
	for (i=0; i<q; i++) {
		scanf("%lld %lld", &l, &r);
		sum = 0;
		for (j=l-1; j<r; j++) {
			sum += arr[(j%N)];
			// printf("%lld : %lld\n", j, arr[(j%N)]);
		}
		
		printf("%lld\n", sum);
	}
	
}
