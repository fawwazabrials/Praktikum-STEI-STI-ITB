#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[11], newline='\n';
    scanf("%s", str);

    int frekuensi[10] = { 0 };
    for(int i=0; i<10; i++) {
        frekuensi[str[i]-'0']++;
    }

    for(int i=0; i<10; i++) {
        printf("%d", frekuensi[i]);
    } printf("%c", newline);
}