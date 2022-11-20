/* File: mesinkarakter.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 16 September 2022
    Topik praktikum     : Prapraktikum #05 - Mesin kata & karakter
    Deskripsi           : Realisasi dari mesinkarakter.h
*/

#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    scanf("%c", &currentChar);
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
    EOP = IsEOP();
    if (!EOP) scanf("%c", &currentChar);
}


char GetCC() {
    return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP() {
    return (currentChar == MARK);
}
/* Mengirimkan true jika currentChar = MARK */