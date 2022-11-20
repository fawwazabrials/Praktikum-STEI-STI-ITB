/* NIM              : 18221067
 * Nama             : Fawwaz Abrial Saffa
 * Tanggal          : 14 November 2022
 * Topik Praktikum  : Pra-Praktikum 10 - Variasi List Linier
 * Deskripsi        : Realisasi template.c
 */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
  // KAMUS LOKAL
  int i;
  address P;

  // ALGORITMA
  if (IsEmpty(L)) return -1;
  else {
    P = First(L);
    for (i=0; i<r; i++) {
        P = Next(P);
    } return Info(P);
  }
}

int main () {
  // KAMUS LOKAL
  List L;
  int r, in;

  // ALGORITMA
  CreateEmpty(&L);
  scanf("%d", &in);
  while (in != 0) {
    InsVLast(&L, in);
    scanf("%d", &in);
  }
  
  scanf("%d", &r);
  if (ElemenKeN(L, r) == -1) printf("List Kosong\n");
  else printf("%d\n", ElemenKeN(L, r));
  return 0;
}