/* FIle : arrayMhs.c */

/*  
 * NIM				: 18221067
 * Nama				: Fawwaz Abrial Saffa
 * Tanggal			: 26 September 2022
 * Topik praktikum	: Praktikum #04 - Array dan ADT List
 * Deskripsi 		: Realisasi dari arrayMhs.h 
 */

#include "arrayMhs.h"
#include <stdio.h>
#include <stdlib.h>

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabMhs, cara deklarasi dan akses: */
/* Deklarasi : T : TabMhs */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMhs *T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	(*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = 0;

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMhs T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.Neff;
/* *** Daya tampung container *** */
int MaxNbEl (TabMhs T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return IdxMax - IdxMin + 1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return IdxMax - IdxMin + 1;
IdxType GetFirstIdx (TabMhs T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return IdxMin;
IdxType GetLastIdx (TabMhs T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return T.Neff;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.Neff;
ElType GetElmt (TabMhs T, IdxType i) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return T.TI[i];

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMhs Tin, TabMhs *Tout) {
	// KAMUS LOKAL
	
	// ALGORIMTA
	(*Tout).Neff = Tin.Neff;
	for(int i = IdxMin; i <= Tin.Neff; i++){
		(*Tout).TI[i] = Tin.TI[i];
	}
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*Tout).Neff = Tin.Neff;
// for(int i = IdxMin; i <= Tin.Neff; i++){
//     (*Tout).TI[i] = Tin.TI[i];
// }
void SetEl (TabMhs *T, IdxType i, ElType v) {
	// KAMUS LOKAL
	
	// ALGORITMA
	(*T).TI[i] = v;
	if ((*T).Neff < i){
		(*T).Neff = i;
	}
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).TI[i] = v;
// if ((*T).Neff < i){
//     (*T).Neff = i;
// }
void SetNeff (TabMhs *T, IdxType N) {
	// KAMUS LOKAL
	
	// ALGORITMA
	(*T).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*T).Neff = N;

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMhs T, IdxType i) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return ((i >= IdxMin) && (i <= IdxMax));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// if ((i >= IdxMin) && (i <= IdxMax)){
//     return true;
// } else {
//     return false;
// }
boolean IsIdxEff (TabMhs T, IdxType i) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return ((i >= IdxMin) && (i <= T.Neff));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// if ((i >= IdxMin) && (i <= T.Neff)){
//     return true;
// } else {
//     return false;
// }

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMhs T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return (T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// if (T.Neff > 0){
//     return false;
// } else {
//     return true;
// }
/* *** Test tabel penuh *** */
boolean IsFull (TabMhs T) {
	// KAMUS LOKAL
	
	// ALGORITMA
	return (T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// if (T.Neff == IdxMax){
//     return true;
// } else {
//     return false;
// }

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMhs T) {
	// KAMUS LOKAL
	IdxType i;
	
	// ALGORITMA
	if (IsEmpty(T)) printf("Tabel kosong\n");
	else {
		for(i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
			printf("%s | %s | %.2f\n", GetElmt(T, i).nama, GetElmt(T, i).nim, GetElmt(T, i).nilai);
		}
	}	
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Contoh print tabel
Test | 12321123 | 3.61
Ini Juga Test | 12321124 | 3.21
Test Lagi | 12321125 | 3.11
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** KONSTRUKTOR MAHASISWA ********** */
ElType MakeMahasiswa (char* Nama, char* NIM, float Nilai) {
	// KAMUS LOKAL
	ElType Mahasiswa;
	
	// ALGORITMA
	Mahasiswa.nama = Nama;
	Mahasiswa.nim = NIM;
	Mahasiswa.nilai = Nilai;
	
	return Mahasiswa;
}
/* Membentuk sebuah Mahasiswa dari komponen-komponennya */
/* I.S. Nama, NIM, Nilai terdefinisi */
/* F.S. Mahasiswa M terbentuk dengan Nama, NIM, Nilai yang sesuai */

/* ********** OPERATOR STATISTIK MAHASISWA ********** */
float RataRata (TabMhs T) {
	// KAMUS LOKAL
	IdxType i;
	float sum=0;
	
	// ALGORITMA
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		sum += GetElmt(T, i).nilai;
	} return (sum/NbElmt(T));
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai rata-rata dari elemen tabel */
float Max (TabMhs T) {
	// KAMUS LOKAL
	IdxType i;
	float maxi = -9999;
	
	// ALGORIMTA
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		if (maxi < GetElmt(T, i).nilai) maxi = GetElmt(T, i).nilai;
	} return maxi;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai maksimum dari elemen tabel */
float Min (TabMhs T) {
	// KAMUS LOKAL
	IdxType i;
	float mini = 9999;
	
	// ALGORIMTA
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		if (mini > GetElmt(T, i).nilai) mini = GetElmt(T, i).nilai;
	} return mini;	
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nilai minimum dari elemen tabel */
char *MaxNama (TabMhs T) {
	// KAMUS LOKAL
	IdxType i;
	float maxi = Max(T);
	char* nimnow = "99999999";
	char* namanow;
	
	// ALGORIMTA
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		if (maxi == GetElmt(T, i).nilai) {
			if (atoi(GetElmt(T, i).nim) < atoi(nimnow)) {
				nimnow = GetElmt(T, i).nim;
				namanow = GetElmt(T, i).nama;
			}
		}
	} return namanow;		
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai tertinggi */
/* Jika ada lebih dari satu mahasiswa dengan nilai tertinggi, maka yang diambil yang nim lebih rendah */
char *MinNama (TabMhs T) {
	// KAMUS LOKAL
	IdxType i;
	float mini = Min(T);
	char* nimnow = "99999999";
	char* namanow;
	
	// ALGORIMTA
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		if (mini == GetElmt(T, i).nilai) {
			if (atoi(GetElmt(T, i).nim) < atoi(nimnow)) {
				nimnow = GetElmt(T, i).nim;
				namanow = GetElmt(T, i).nama;
			}
		}
	} return namanow;		
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan nama mahasiswa dengan nilai terendah */
/* Jika ada lebih dari satu mahasiswa dengan nilai terendah, maka yang diambil yang nim lebih rendah */
int JumlahJurusan (TabMhs T, char* Jurusan) {
	// KAMUS LOKAL
	IdxType i;
	int cnt=0;
	
	// ALGORITMA
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		if ((Jurusan[0] == GetElmt(T, i).nim[0]) && 
		    (Jurusan[1] == GetElmt(T, i).nim[1]) && 
		    (Jurusan[2] == GetElmt(T, i).nim[2])) {
			cnt++;
		}
	}
	
	return cnt;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Menghasilkan jumlah mahasiswa yang berasal dari jurusan Jurusan, yang berbentuk 3 angka (contoh: 182) */
/* Jika tidak ada mahasiswa yang berasal dari jurusan Jurusan, maka menghasilkan 0 */
