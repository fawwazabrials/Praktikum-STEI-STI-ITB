#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("masuk");

Stack subtract (Stack big, Stack smol, Stack* ans);
/* int(big) - int(smol)
   Mengurangkan nilai angka yang disimpan dalam stack big dengan stack 
   smol kemudian hasil disimpan di dalam stack ans*/
boolean compare (Stack a, Stack b);
/* Mengembalikan true bila nilai didalam stack a lebih besar daripada stack b */

int main() {
    // KAMUS UTAMA
    char* str1;
    char* str2;
    int i, start=0, len, val;
    boolean s2_bigger = false;
    Stack s1, s2;
    Stack ans, rev;

    // ALGORITMA UTAMA
    str1 = (char *) malloc (100 * sizeof(char));
    str2 = (char *) malloc (100 * sizeof(char));

    scanf("%s", str1);
    scanf("%s", str2);

    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&ans);
    // push digits to stack
    while (*str1 != '\0') {
        Push(&s1, *str1- '0');
        str1++;
    } while (*str2 != '\0') {
        Push(&s2, *str2- '0');
        str2++;
    }

    if (Top(s1) > Top(s2)) {
        
        subtract(s1, s2, &rev);
    } else if (Top(s1) < Top(s2)) {
        subtract(s2, s1, &rev);
        printf("-");
    } else {
        if (compare(s2, s1)) { // if s2 bigger
            subtract(s2, s1, &rev);
            printf("-");
        } else { // if s1 bigger
            subtract(s1, s2, &rev);
        }
    }

    len = Top(rev);
    for (i=0; i<=len; i++) {
        Pop(&rev, &val);
        Push(&ans, val);
    }

    while (start < Top(ans) && ans.T[start] == 0) start++;

    for (i=start; i<Top(ans); i++) {
        printf("%d", ans.T[i]);
    } printf("%d\n", ans.T[i]);

}

Stack subtract (Stack big, Stack smol, Stack* ans) {
/* int(big) - int(smol)
   Mengurangkan nilai angka yang disimpan dalam stack big dengan stack 
   smol kemudian hasil disimpan di dalam stack ans*/
    // KAMUS LOKAL
    int borrow=0, hasil, val1, val2;

    // ALGORITMA
    CreateEmpty(ans);
    while (!IsEmpty(smol)) {
        Pop(&big, &val1);
        Pop(&smol, &val2);

        hasil = val1 - val2 - borrow;
        if (hasil < 0) {
            hasil += 10;
            borrow = 1;
        } else borrow = 0;

        Push(ans, hasil);
    } while (!IsEmpty(big)) {
        Pop(&big, &val1);
        hasil = val1 - borrow;
        if (hasil < 0) {
            hasil += 10;
            borrow = 1;
        } else borrow = 0;

        Push(ans, hasil);
    } 
}

boolean compare (Stack a, Stack b) {
/* Mengembalikan true bila nilai didalam stack a lebih besar daripada stack b */
    // KAMUS LOKAL
    int i;

    // ALGORITMA    
    for (i = 0; i <= Top(a); i++) {
        if ((a.T[i] - '0') < (b.T[i] - '0')) return false;
        else if ((a.T[i] - '0') > (b.T[i] - '0')) return true;
    } return false;
}