/* File: queue.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 Oktober 2022
    Topik praktikum     : Prapraktikum #06 - Queue
    Deskripsi           : Realisasi dari queue.h
*/

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    // KAMUS LOKAL

    // AGLORITMA
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    // KAMUS LOKAL

    // AGLORITMA
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q) {
    // KAMUS LOKAL

    // AGLORITMA
    return (length(q) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q) {
    // KAMUS LOKAL

    // AGLORITMA
    if (isEmpty(q)) return 0;
    else if(IDX_TAIL(q) >= IDX_HEAD(q)) return IDX_TAIL(q) - IDX_HEAD(q) +1;
    else return IDX_TAIL(q) + 1 + (CAPACITY - IDX_HEAD(q));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
    // KAMUS LOKAL

    // AGLORITMA
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;  
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }

    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val) {
    // KAMUS LOKAL

    // AGLORITMA
    *val = HEAD(*q);

    if (length(*q) == 1) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;  
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q) {
    // KAMUS LOKAL
    int i, val;

    // AGLORITMA
    if (isEmpty(q)) printf("[]\n");
    else {
        printf("[");
        for (i = 0; i<length(q)-1; i++) {
            printf("%d,", q.buffer[(IDX_HEAD(q) + i) % CAPACITY]);
        } printf("%d]\n", q.buffer[IDX_TAIL(q)]);
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */