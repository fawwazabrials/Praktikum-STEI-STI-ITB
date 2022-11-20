/* File: circular_queue.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 Oktober 2022
    Topik praktikum     : Prapraktikum #06 - Queue
    Deskripsi           : Realisasi dari circular_queue.h
*/

#include "circular_queue.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q) {
    // KAMUS LOKAL

    // AGLORITMA
    return (Q.HEAD == NIL) && (Q.TAIL == NIL); 
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q) {
    // KAMUS LOKAL

    // AGLORITMA
    return Length(Q) == MaxLength(Q);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q) {
    // KAMUS LOKAL

    // AGLORITMA
    if(IsEmpty(Q)) return 0;
    else if(Q.HEAD <= Q.TAIL) return Q.TAIL - Q.HEAD +1;
    else return Q.TAIL +1 + (MaxLength(Q) - Q.HEAD);
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q) {
    // KAMUS LOKAL

    // AGLORITMA
    return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max) {
    // KAMUS LOKAL
    Queue Q;

    // ALGORITMA
    Q.Tab = (ElType*) malloc (sizeof(ElType*) * Max);
    Q.HEAD = NIL;
    Q.TAIL = NIL;

    if (Q.Tab == NULL) Q.MaxEl = 0;
    else Q.MaxEl = Max;

    return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q) {
    // KAMUS LOKAL

    // AGLORITMA
    free((*Q).Tab);
    (*Q).MaxEl = 0;
    (*Q).HEAD = NIL;
    (*Q).TAIL - NIL;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(*Q)) {
        (*Q).HEAD = 0;
        (*Q).TAIL = 0;  
    } else {
        (*Q).TAIL = ((*Q).TAIL + 1) % MaxLength(*Q);
    }

    (*Q).Tab[(*Q).TAIL] = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q) {
    // KAMUS LOKAL
    ElType front = Front(*Q);

    // AGLORITMA
    if (Length(*Q) == 1) {
        (*Q).HEAD = NIL;
        (*Q).TAIL = NIL;  
    } else {
        (*Q).HEAD = ((*Q).HEAD + 1) % MaxLength(*Q);
    }

    return front;
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q) {
    // KAMUS LOKAL

    // AGLORITMA
    return Q.Tab[Q.HEAD];
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */