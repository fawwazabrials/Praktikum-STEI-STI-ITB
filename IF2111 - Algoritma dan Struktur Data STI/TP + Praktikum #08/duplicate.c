/* File : duplicate.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 28 Oktober 2022
    Topik praktikum     : Praktikum #08 - Set, Map dan Hashtable
    Deskripsi           : Realisasi dari duplicate.h
*/

#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize) {
	// KAMUS LOKAL
	Set S;
	int i;
	
	// ALGORITMA
	CreateEmpty(&S);
	for (i=0; i<arrSize; i++) {
		Insert(&S, arr[i]);
	} return S;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize) {
	// KAMUS LOKAL
	Set S;
	int i, j, temp, len=0;
	
	// ALGORITMA
	*arrResSize = 0;
	S = arrToSet(arr, arrSize);
	for (i=0; i<S.Count; i++) {
		arrRes[i] = S.Elements[i];
		len++;
	}
	
	for (i=0; i < len; i++) {
		for (j=0; j < len; j++) {
			if (arrRes[j+1] > arrRes[j]) {
				temp = arrRes[j+1];
				arrRes[j+1] = arrRes[j];
				arrRes[j] = temp; 
			}
		}
	}
	
	*arrResSize = len;
}
