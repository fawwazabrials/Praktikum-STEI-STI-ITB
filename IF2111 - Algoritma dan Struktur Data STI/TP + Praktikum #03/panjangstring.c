#include <stdio.h>
#include "panjangstring.h"

int panjangString(char* c) {
    int cnt = 0;
    while (*c != '\0') {
        cnt++;
        c++;
    } return cnt;
}