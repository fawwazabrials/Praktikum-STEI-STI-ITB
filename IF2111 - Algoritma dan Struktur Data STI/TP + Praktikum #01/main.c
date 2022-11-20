#include <stdio.h>

int main() {
    int s, j, m, d;
    scanf("%d", &s);

    j = s/3600; m = (s-j*3600)/60; d = s - j*3600 - m*60;

    printf("%d detik = %d jam %d menit %d detik\n", s, j, m, d);
    return 0;
}