/* File : linkstack.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 15 November 2022
 * Topik Praktikum  : Pra-Praktikum 10 - Variasi List Linier
 * Deskripsi        : Realisasi linkstack.c
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
 
/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X) {
    // KAMUS LOKAL

    // ALGORITMA
    *P = (Node*) malloc (sizeof(Node));
    if (*P != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    } else *P = Nil;
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P) {
	// KAMUS LOKAL
	
	// ALGORITMA
	free(P);
}
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S) {
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty(Stack *S) {
	Top(*S) = Nil;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push(Stack *S, ElType X) {
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	Alokasi(&P, X);
	if (P != Nil) {
		Next(P) = Top(*S);
		Top(*S) = P;
	}
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop(Stack *S, ElType *X) {
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	*X = InfoTop(*S);
	P = Top(*S);
	Top(*S) = Next(P);
	Next(P) = Nil;
	Dealokasi(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
