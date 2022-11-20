/* File : linkdummy.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 15 November 2022
 * Topik Praktikum  : Pra-Praktikum 10 - Variasi List Linier
 * Deskripsi        : Realisasi linkdummy.c
 */
 
#define dummy 0
 
#include <stdio.h>
#include <stdlib.h>
#include "linkdummy.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
	return Info(First(L)) == dummy && Info(Last(L)) == dummy;
}
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L) {
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	P = Alokasi(dummy);
	if (P != Nil) {
		First(*L) = P;
		Last(*L) = P;
	} else {
		First(*L) = Nil;
		Last(*L) = Nil;
	}
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X) {
    // KAMUS LOKAL
    address p;

    // ALGORITMA
    p = (Node*) malloc (sizeof(Node));
    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    } else return Nil;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P) {
    // KAMUS LOKAL

    // ALGORITMA
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** SEARCHING ******************/
address Search(List L, ElType X) {
    // KAMUS LOKAL
    boolean found;
    address P;

    // ALGORITMA
    found = false;
    P = First(L);
    while (P != Last(L) && !found) {
        if (Info(P) == X) found = true;
        else P = Next(P);
    }

    if (found) return P;
    else return Nil;
}
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X) {
    // KAMUS LOKAL
	address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil) {
		Next(P) = First(*L);
		First(*L) = P;
	}
}
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
void InsertLast(List *L, ElType X) {
    // KAMUS LOKAL
	address P, loc;

    // ALGORITMA
    if (IsEmpty(*L)) InsertFirst(L, X);
    else {
		P = Alokasi(X);
		if (P != Nil) {
			loc = First(*L);
			while (Next(loc) != Last(*L)) {
				loc = Next(loc);
			}
		
			Next(loc) = P;
			Next(P) = Last(*L);
		}
	}
}
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X) {
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	P = First(*L);
	First(*L) = Next(P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X) {
	// KAMUS LOKAL
	address P, Prec;
	
	// ALGORITMA
	P = First(*L); Prec = Nil;
	while (Next(P) != Last(*L)) {
		Prec = P; P = Next(P);
	}
	
	*X = Info(P);
	if (Prec == Nil) {
		First(*L) = Last(*L);
	} else {
		Next(Prec) = Last(*L);
	}
	
	Dealokasi(P);
}
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
