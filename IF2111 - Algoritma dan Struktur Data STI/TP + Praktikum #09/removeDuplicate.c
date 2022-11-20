/* FIle : removeDuplicate.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 7 November 2022
 * Topik Praktikum  : Pra-Praktikum 9 - List Linier
 * Deskripsi        : Realisasi removeDuplicate.h
 */
 
 #include "removeDuplicate.h"
 
List removeDuplicate(List l) {
	// KAMUS LOKAL
	address P;
	List L, ans;
	
	// ALGORITMA
	CreateEmpty(&L);
	P = First(l);
	while (P != Nil) {
		if (Search(L, Info(P)) == Nil) InsVLast(&L, Info(P));
		P = Next(P);
	}
	

	
	
	
	return L;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/

