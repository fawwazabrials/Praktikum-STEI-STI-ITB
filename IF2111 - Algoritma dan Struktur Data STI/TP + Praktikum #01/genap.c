#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    if(a%2==0 && (a/2)%2==0) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }

    return 0;
}