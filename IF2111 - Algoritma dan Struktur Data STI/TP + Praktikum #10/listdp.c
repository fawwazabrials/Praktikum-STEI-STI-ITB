/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 4 November 2022
 * Topik Praktikum  : Pra-Praktikum 10 - Variasi List Linier
 * Deskripsi        : Realisasi listdp.h
 */

#include "listdp.h"
#include "stdio.h"
#include "stdlib.h"

/* #define Nil NULL

Definisi Type Data
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
	address prev;
} ElmtList;
typedef struct {
	address First;
	address Last;
} List;

Definisi list :
List kosong : First(L) = Nil dan Last(L) = Nil
Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P)
Elemen terakhir list: Last(L)

Notasi Akses
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    return First(L) == Nil && Last(L) == Nil;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    // KAMUS LOKAL

    // ALGORITMA
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    // KAMUS LOKAL
    address p;

    // ALGORITMA
    p = (ElmtList*) malloc (sizeof(ElmtList));
    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        Prev(p) = Nil;
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    // KAMUS LOKAL
    boolean found;
    address P;

    // ALGORITMA
    found = false;
    P = First(L);
    while (P != Nil && !found) {
        if (Info(P) == X) found = true;
        else P = Next(P);
    }

    if (found) return P;
    else return Nil;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(*L)) {
        Next(P) = Nil;
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P) {
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(*L)) {
        Prev(P) = Nil;
        First(*L) = P;
        Last(*L) = P;
    } else {
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec) {
    // KAMUS LOKAL

    // ALGORITMA
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
    if (Next(P) == Nil) Last(*L) = P;
    else Prev(Next(P)) = P;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ) {
    // KAMUS LOKAL

    // ALGORITMA
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
	if (Prev(P) == Nil) First(*L) = P;
	else Next(Prev(P)) = P;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    // KAMUS LOKAL

    // ALGORITMA
    *P = First(*L);
    if (Next(*P) == Nil) {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else {
        First(*L) = Next(*P);
        Prev(First(*L)) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P) {
    // KAMUS LOKAL

    // ALGORITMA
    *P = Last(*L);
    if (Prev(*P) == Nil) {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else {
        Last(*L) = Prev(*P);
        Next(Last(*L)) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Search(*L, X);
    if (P != Nil) {
        if (P == First(*L)) DelFirst(L, &P);
        else if (P == Last(*L)) DelLast(L, &P);
        else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
        } Dealokasi(P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec) {
    // KAMUS LOKAL

    // ALGORITMA
    *Pdel = Next(Prec);
    if (*Pdel == Nil) {
        Next(Prec) = Next(*Pdel);
        if (Next(Prec) == Nil) Last(*L) = Prec;
        else Prev(Next(Prec)) = Prev(Prev(Next(Prec)));
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ) {
    // KAMUS LOKAL

    // ALGORITMA
    *Pdel = Prev(Succ);
	if (*Pdel != Nil) {
		Prev(Succ) = Prev(*Pdel);
		if (Prev(Succ) == Nil) First(*L) = Succ;
		else Next(Prev(Succ)) = Next(Next(Prev(Succ)));
	}
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
    // KAMUS LOKAL
    address P;

    // ALGORIMTA
    P = First(L);
    printf("[%d", Info(P));
    P = Next(P);
    while (P != Nil) {
        printf(",%d", Info(P));
        P = Next(P);
    } printf("]");
}

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Last(L);
    printf("[%d", Info(P));
    P = Prev(P);
    while (P != Nil) {
        printf(",%d", Info(P));
        P = Prev(P);
    } printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */