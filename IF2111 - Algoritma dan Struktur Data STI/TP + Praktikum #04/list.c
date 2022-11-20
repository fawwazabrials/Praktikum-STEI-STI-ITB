/* File: list.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 25 September 2022
    Topik praktikum     : Prapraktikum #04 - Array dan ADT List
    Deskripsi           : Realisasi dari list.h
*/

#include "list.h"
#include <stdio.h>

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList() {
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
    // KAMUS LOKAL
    List L;
    
    // ALGORITMA
    L.A[MaxEl];
    L.A[0] = Mark;
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L) {
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    // KAMUS LOKAL

    // ALGORITMA
    return (L.A[0] == Mark);
}


/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i) {
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
    // KAMUS LOKAL

    // ALGORITMA
    return (L.A[i]);
}


/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
    // KAMUS LOKAL
    
    // ALGORITMA
    if (i > LastIdx(*L)) (*L).A[Length(*L)+1] = Mark;
    (*L).A[i] = v;
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
    // KAMUS LOKAL
    IdxType i=0;
    int len=0;

    // ALGORITMA
    while (Get(L, i) != Mark && i<MaxEl-1) {
        len++; i++;
    } if (Get(L, i) != Mark) len++;

    return len;    
}


/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L) {
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
    // KAMUS LOKAL

    // ALGORITMA
    return 0;
}

IdxType LastIdx(List L) {
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    // KAMUS LOKAL
    IdxType i=0;

    // ALGORITMA
    return (Length(L)-1);

}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
    // KAMUS LOKAL

    // ALGORITMA
    return (i >= FirstIdx(L) && i < MaxEl);
}


boolean IsIdxEff (List L, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    // KAMUS LOKAL

    // ALGORITMA
    return (i >= FirstIdx(L) && i < LastIdx(L));
}


/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X) {
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
    // KAMUS LOKAL
    boolean found=false;
    IdxType i=0;

    // ALGORITMA
    while (!found && i<Length(L)) {
        if (L.A[i] == X) found = true;
        i++;
    }

    return (found);
}


void InsertFirst(List *L, ElType X) {
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */ 
    // KAMUS LOKAL

    // ALGORITMA
    InsertAt(L, X, FirstIdx(*L));
}


void InsertAt(List *L, ElType X, IdxType i) {
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    // KAMUS LOKAL
    IdxType j;

    // ALGORITMA
    Set(L, Length(*L)+1, Mark);
    for (j=Length(*L); j>i; j--) {
        Set(L, j, Get(*L, j-1));
    } Set(L, j, X);
}


void InsertLast(List *L, ElType X) {
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
    // KAMUS LOKAL

    // ALGORITMA
    InsertAt(L, X, Length(*L));
}


void DeleteFirst(List *L) {
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
    // KAMUS LOKAL
    
    // ALGORITMA
    DeleteAt(L, 0);
}

void DeleteAt(List *L, IdxType i) {
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
    // KAMUS LOKAL
    IdxType j;

    // ALGORITMA
    for (j=i; j < Length(*L) - 1; j++) {
        Set(L, j, Get(*L, j+1));
    } Set(L, j, Mark);
}


void DeleteLast(List *L) {
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
    // KAMUS LOKAL

    // ALGORITMA
    DeleteAt(L, LastIdx(*L));
}


List Concat(List L1, List L2) {
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
    // KAMUS LOKAL
    IdxType i;
    List L;

    // ALGORITMA
    for (i=FirstIdx(L); i<Length(L1); i++) {
        Set(&L, i, Get(L1, i));
    }

    for (i=Length(L1); i<Length(L1)+Length(L2)-1; i++) {
        Set(&L, i, Get(L2, i-Length(L1)));
    }

    Set(&L, i+1, Mark);

    return L;
}
