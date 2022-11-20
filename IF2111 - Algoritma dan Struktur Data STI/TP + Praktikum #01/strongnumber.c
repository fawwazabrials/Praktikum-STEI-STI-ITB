#include <stdio.h>

int main() { 
    int ori, num, sum=0, faktorial;
    scanf("%d", &num);

    ori = num;

    while (num > 0) {
        faktorial = 1;
        for (int i=1; i<=num%10; i++) {
            faktorial *= i;
        } 
        sum += faktorial;
        num /= 10;
    }

    if (sum == ori) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}