/* File : browserhistory.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 24 Oktober 2022
    Topik praktikum     : Praktikum #07 - Stack
    Deskripsi           : Realisasi dari browserhistory.h
*/

#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url) {
    // KAMUS LOKAL

    // ALGORITMA
    Push(openedTab, url);
}
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */

char *currentUrl(Stack *openedTab) {
    // KAMUS LOKAL

    // ALGORITMA
    return (InfoTop(*openedTab));
}
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */

char *browserHistoryBack(Stack *openedTab, Stack *history, int steps) {
    // KAMUS LOKAL
    int i;
    infotype val;

    // ALGORITMA
    for (i=0; i<steps; i++) {
        Pop(openedTab, &val);
        Push(history, val);
    } return currentUrl(openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps) {
    // KAMUS LOKAL
    int i;
    infotype val;

    // ALGORITMA
    for (i=0; i<steps; i++) {
        Pop(history, &val);
        Push(openedTab, val);
    } return currentUrl(openedTab);
}
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */

void browserHistoryFree(Stack *history) {
    // KAMUS LOKAL

    // ALGORITMA
    CreateEmpty(history);
}
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */