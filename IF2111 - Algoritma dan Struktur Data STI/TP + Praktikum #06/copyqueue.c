/* File : copyqueue.c */

/*    
 * NIM				: 18221067
 * Nama				: Fawwaz Abrial Saffa
 * Tanggal			: 17 Oktober 2022
 * Topik praktikum	: Praktikum #6 - Queue
 * Deskripsi		: Realisasi dari copyqueue.h
*/

#include "queue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput) {
	// KAMUS LOKAL
	ElType val;
	int i, len=length(*queueInput);
	
	// ALGORITMA
	CreateQueue(queueOutput);
	for (i=0; i<len; i++) {
		dequeue(queueInput, &val);
		enqueue(queueInput, val);
		enqueue(queueOutput, val);
	}
}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/

