/* File : tanpaBomb.c */

/*    
 * NIM				: 18221067
 * Nama				: Fawwaz Abrial Saffa
 * Tanggal			: 17 Oktober 2022
 * Topik praktikum	: Praktikum #6 - Queue
 * Deskripsi		: Realisasi dari tanpaBomb.h
*/

Queue tanpaBomb(Queue queue, ElType bomb) {
	// KAMUS LOKAL
	Queue tanpabomb;
	int i, val, len=length(queue);
	
	// ALGORITMA
	for (i=0; i<len); i++) {
		dequeue(&queue, &val);
		if (val != bomb) enqueue(&bomb, val);
	} return tanpabomb;
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/
