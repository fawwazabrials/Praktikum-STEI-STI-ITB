/* File : map.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 28 Oktober 2022
    Topik praktikum     : Praktikum #08 - Set, Map dan Hashtable
    Deskripsi           : Realisasi dari map.h
*/

#define DEBUG printf("masuk\n");

#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M) {
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

    // KAMUS LOKAL

    // ALGORITMA
    (*M).Count = Nil;
}


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M) {
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

    // KAMUS LOKAL

    // ALGORITMA
    return (M).Count == Nil;
}


boolean IsFull(Map M) {
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

    // KAMUS LOKAL

    // ALGORITMA
    return (M).Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k) {
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

    // KAMUS LOKAL
    boolean found = false;
    int i=0;

    // ALGORITMA
    while (!found && i < M.Count) {
        if (M.Elements[i].Key == k) found = true;
        else i++;
    }

    if (found) return M.Elements[i].Value;
    else return Undefined;
}


void Insert(Map *M, keytype k, valuetype v) {
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

    // KAMUS LOKAL

    // ALGORITMA
    if (!IsMember(*M, k)) {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count++].Value = v;
    }
}


void Delete(Map *M, keytype k) {
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

    // KAMUS LOKAL
    boolean found = false;
    int i;

    // ALGORITMA
    for (i=0; i<(*M).Count; i++) {
        if ((*M).Elements[i].Key == k) {
            found = true;
            (*M).Count--;
        } 
        
        if (found) {
            (*M).Elements[i].Key = (*M).Elements[i+1].Key;
            (*M).Elements[i].Value = (*M).Elements[i+1].Value;
        }
    }
}

boolean IsMember(Map M, keytype k) {
/* Mengembalikan true jika k adalah member dari M */

    // KAMUS LOKAL
    boolean found = false;
    int i=0;

    // ALGORITMA
    while (!found && i < M.Count) {
        if (M.Elements[i].Key == k) found = true;
        i++;
    } return found;
}