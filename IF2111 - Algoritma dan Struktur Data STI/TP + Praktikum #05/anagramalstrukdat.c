/* File: anagramalstrukdat.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 September 2022
    Topik praktikum     : Praktikum #05 - Mesin kata & karakter
    Deskripsi           : Realisasi anagramalstrukdat.h
*/

#include <stdio.h>
#include "anagramalstrukdat.h"

int stringLength(char *string) {
    // KAMUS LOKAL
	int count = 0;

    // ALGORITMA
	while (*string != '\0') {
		count++, string++;
	} return count;
}

Word toKata(char *command) {
    // KAMUS LOKAL
	int i;
	Word kata;

    // ALGORITMA
	kata.Length = stringLength(command);
	for (i = 0; i < kata.Length; i++) {
		kata.TabWord[i] = command[i];
	} return kata;
}

boolean isAnagram(Word string1, Word string2) {
    // KAMUS LOKAL
	int i;
	int alfabet1[26] = {0}, alfabet2[26] = {0};

    // ALGORITMA
	for (i = 0; i < stringLength(string1.TabWord); i++) {
		if ('A' <= string1.TabWord[i] && string1.TabWord[i] <= 'Z') alfabet1[string2.TabWord[i] - 65]++;
		else if ('a' <= string1.TabWord[i] && string1.TabWord[i] <= 'z') alfabet1[string1.TabWord[i] - 97]++;
	}
	for (i = 0; i < stringLength(string2.TabWord); i++)	{
		if ('A' <= string2.TabWord[i] && string2.TabWord[i] <= 'Z') alfabet2[string2.TabWord[i] - 65]++;
		else if ('a' <= string2.TabWord[i] && string2.TabWord[i] <= 'z') alfabet2[string2.TabWord[i] - 97]++;
	}
	for (i = 0; i < 26; i++) {
		if (alfabet1[i] != alfabet2[i]) return false;
	} return true;
}

void anagramalstrukdat(int *frek) {
    // KAMUS LOKAL
    Word alstrukdat;

    // ALGORITMA
	alstrukdat = toKata("alstrukdat");
	STARTWORD();
	while (!isEndWord())
	{
		*frek += isAnagram(alstrukdat, currentWord);
		ADVWORD();
	}
}