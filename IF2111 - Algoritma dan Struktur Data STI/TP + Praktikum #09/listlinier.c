/* File : listlinier.c */

/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 4 November 2022
 * Topik Praktikum  : Pra-Praktikum 9 - List Linier
 * Deskripsi        : Realisasi listlinier.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    // KAMUS LOKAL

    // ALGORITMA
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P =  (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } 
    return Nil;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P) {
    // KAMUS LOKAL

    // ALGORITMA
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    // KAMUS LOKAL
    address P;
    boolean found;

    // ALGORITMA
    found = false;
    P = First(L);
    while (P != Nil && !found) {
        if (X == Info(P)) found = true;
        else P = Next(P);
    } 
    
    if (found) return P;
    else return Nil;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil) InsertFirst(L, P);

}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != Nil) InsertLast(L, P);
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
    Dealokasi(&P);
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
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    // KAMUS LOKAL

    // ALGORITMA
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec) {
    // KAMUS LOKAL

    // ALGORITMA
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P) {
    // KAMUS LOKAL
    address last;

    // ALGORITMA
    if (IsEmpty(*L)) InsertFirst(L, P);
    else {
        last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }

        InsertAfter(L, P, last);

    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    // KAMUS LOKAL

    // ALGORITMA
    *P = First(*L);
    if(Next(First(*L)) == Nil) {
        CreateEmpty(L);
        return;
    }
    First(*L) = Next(First(*L));
    Next(*P) =Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X) {
    // KAMUS LOKAL
    address P, prev, temp;
    boolean found;

    // ALGORITMA
    P = First(*L);
    prev = Nil;
    found = false;

    while (P != Nil && !found) {
        if (Info(P) == X) found = true;
        else {
            prev = P;
            P = Next(P);
        }
    }

    if (found) {
        if (prev == Nil) DelFirst(L, &temp);
        else DelAfter(L, &temp, prev);
        Dealokasi(&temp);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P) {
    // KAMUS LOKAL
    address last, prev;

    // ALGORITMA
    last = First(*L);
    prev = Nil;
    while(Next(last) != Nil) {
        prev = last;
        last = Next(last);
    }
    if(prev == Nil) DelFirst(L,P);
    else DelAfter(L,P,prev);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec) {
    // KAMUS LOKAL
    address temp;
    boolean found;
    
    // ALGORITMA
    found = false;
    temp = First(*L);
    while(temp != Nil && !found) {
        if(temp == Prec) found = true;
        else temp = Next(temp);
    }

    *Pdel = Next(temp);
    Next(temp) = Next(Next(temp));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) printf(",");
    } printf("]");

}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L) {
    // KAMUS LOKAL
    address P;
    int cnt = 0;

    // ALGORITMA
    P = First(L);
    while (P != Nil) {
        cnt++;
        P = Next(P);
    }
    return cnt;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
    // KAMUS LOKAL
    infotype maxi;
    address P;

    // ALGORITMA
    P = First(L);
    maxi = Info(P);
    while (P != Nil) {
        if (Info(P) > maxi) maxi = Info(P);
        P = Next(P);
    } return maxi;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L) {
    // KAMUS LOKAL
    
    // ALGORITMA
    return Search(L, Max(L));
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L) {
    // KAMUS LOKAL
    infotype mini;
    address P;

    // ALGORITMA
    P = First(L);
    mini = Info(P);
    while (P != Nil) {
        if (Info(P) < mini) mini = Info(P);
        P = Next(P);
    } return mini;   
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L) {
    // KAMUS LOKAL

    // ALGORITMA
    return Search(L, Min(L));
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L) {
    // KAMUS LOKAL
    float sum=0, cnt=0;
    address P;

    // ALGORITMA
    P = First(L);
    while (P != Nil) {
        sum += Info(P);
        cnt++;
        P = Next(P);
    } return sum/cnt;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L) {
    // KAMUS LOKAL
    address P, prev, temp;

    // ALGORITMA
    P = First(*L);
    prev = Nil;

    while (P != Nil) {
        temp = P;
        P = Next(P);
        Next(temp) = prev;
        prev = temp; 
    }
    First(*L) = temp;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3) {
    // KAMUS LOKAL
    address loc;

    // ALGORITMA
    CreateEmpty(L3);

    if (IsEmpty(*L1)) First(*L3) = First(*L2);
    else {
        First(*L3) = First(*L1);
        loc = First(*L1);
        while (Next(loc) != Nil) loc = Next(loc);
        Next(loc) = First(*L2);
    }

    CreateEmpty(L1); CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */