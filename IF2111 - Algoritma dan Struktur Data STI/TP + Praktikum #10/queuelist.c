/* File : queuelist.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 15 November 2022
 * Topik Praktikum  : Pra-Praktikum 10 - Variasi List Linier
 * Deskripsi        : Realisasi queuelist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X) {
    // KAMUS LOKAL

    // ALGORITMA
    *P = (ElmtQueue*) malloc (sizeof(ElmtQueue));
    if (*P != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    } else *P = Nil;
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi(address P) {
	// KAMUS LOKAL
	
	// ALGORITMA
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty(Queue Q) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return Head(Q) == Nil && Tail(Q) == Nil;
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q) {
	// KAMUS LOKAL
	int cnt=0;
	address P;
	
	// ALGORITMA
	P = Head(Q);
	while (P != Nil) {
		cnt++;
		P = Next(P);
	} return cnt;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue *Q) {
	// KAMUS LOKAL
	
	// ALGORITMA
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X) {
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	Alokasi(&P, X);
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Dequeue(Queue *Q, infotype *X) {
	// KAMUS LOKAL
	address P;
	
	// ALGORITMA
	P = Head(*Q);
    *X = Info(P);
    Head(*Q) = Next(P);
    if (Head(*Q) == Nil) {
		Tail(*Q) = Nil;
	}
	
	Next(P) = Nil;
	Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
