/* FIle : cache.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 7 November 2022
 * Topik Praktikum  : Pra-Praktikum 9 - List Linier
 * Deskripsi        : Realisasi listlinier.h
 */

#include <stdio.h>
#include "listlinier.h"

int main() {
	// KAMUS LOKAL
	int i, N, Q;
	address P, temp;
	infotype x, in;
	List L;
	
	// ALGORITMA
	scanf("%d %d", &N, &Q);
	CreateEmpty(&L);
	for (i=1; i<=N; i++) {
		InsVLast(&L, i);
	}
	
	for (i=0; i<Q; i++) {
		scanf("%d", &in);
		P = Search(L, in);
		if (P == Nil) { // ganemu
			printf("miss ");
			InsVFirst(&L, in);
			DelVLast(&L, &x);
		}
		else {
			printf("hit ");
			DelP(&L, in);
			InsVFirst(&L, in);
		}
		
		PrintInfo(L); printf("\n");
	}
	return 0;
}
