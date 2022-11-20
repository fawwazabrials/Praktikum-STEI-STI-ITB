/* FIle : MinMax.c */

/*  
 * NIM				: 18221067
 * Nama				: Fawwaz Abrial Saffa
 * Tanggal			: 26 September 2022
 * Topik praktikum	: Praktikum #04 - Array dan ADT List
 * Deskripsi 		: Realisasi dari MinMax.h 
 */

#include "list.h"
#include "MinMax.h"
#include <stdio.h>

List MinMax(List L) {
	// KAMUS LOKAL
	List minmax;
	IdxType i, maxIdx, minIdx;
	int maxi=-9999, mini=9999;

	// ALGORITMA
	minmax = MakeList();

	for (i = FirstIdx(L); i<= LastIdx(L); i++) {
		Set(&minmax, i, Get(L, i));
	}

	for (i = FirstIdx(L); i<= LastIdx(L); i++) {
		// printf("%d : %d\n", i, Get(L,i));
		if (Get(L, i) > maxi) {
			maxi = Get(L,i);
			maxIdx = i;
		}
		
		if (Get(L, i) < mini) {
			mini = Get(L,i);
			minIdx = i;
		}
	}

	DeleteAt(&minmax, minIdx);
	if (minIdx >= maxIdx) DeleteAt(&minmax, maxIdx);
	else DeleteAt(&minmax, maxIdx-1);
	
	InsertLast(&minmax, mini); 
	InsertLast(&minmax, maxi);

	// printf("maxi = %d\n", maxi);
	// printf("mani = %d\n", mini);

	return minmax;
}



