/* File: hitungfrekuensi.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 September 2022
    Topik praktikum     : Praktikum #05 - Mesin kata & karakter
    Deskripsi           : Realisasi hitungfrekuensi.h
*/

#include <stdio.h>
#include "boolean.h"
#include "mesinkarakterv2.h"
#include "mesinkata.h"

int main() {
    // KAMUS LOKAL
	int nFirstWord, i;

    // ALGORITMA
	STARTWORD();
	nFirstWord = currentWord.Length;
    while (!isEndWord()) {
		for (i = 0; i < currentWord.Length; i++) {
			currentWord.TabWord[i] += nFirstWord;
			while (currentWord.TabWord[i] > 'Z') {
				currentWord.TabWord[i] -= 26;
			}
			printf("%c", currentWord.TabWord[i]);
		}
		ADVWORD();
		if (!isEndWord() || currentWord.Length == 0) printf(" ");
		else printf(".");
	} printf("\n");
}