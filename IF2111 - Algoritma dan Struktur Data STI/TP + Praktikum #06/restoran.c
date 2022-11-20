/* File : restoran.c */

/*    
 * NIM				: 18221067
 * Nama				: Fawwaz Abrial Saffa
 * Tanggal			: 17 Oktober 2022
 * Topik praktikum	: Praktikum #6 - Queue
 * Deskripsi		: Mengeluarkan jumlah makanan, waktu minimum serta waktu maksimum dari 1 hari di restoran Ibu Gra, makanan yang valid adalah makanan yang telah disajikan
*/

#include <stdio.h>
#include "queue.h"

int main() {
	// KAMUS UTAMA
	Queue restoran;
	int order, val, time, max=-9999999, min=9999999, nbOR=0;
	
	// ALGORITMA
	CreateQueue(&restoran);
	scanf("%d", &order);
	while (order != 0) {
		if (order == 1) {
			scanf("%d", &time);
			if (time > 0) enqueue(&restoran, time);
		} else if (order == 2) {
			if (!isEmpty(restoran)) {
				dequeue(&restoran, &val);
				if (val > max) max = val;
				if (val < min) min = val;
				nbOR++;
			}
			
		}
		scanf("%d", &order);
	}
	if (nbOR == 0) printf("0\n0\n0\n");
	else printf("%d\n%d\n%d\n", nbOR, min, max);
}
