#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype i, el, first, second, next;
    scanf("%d", &el);

    // Masukkan kode program disini

    if (el == 0) {       
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
		scanf("%d", &first);
        InsVLast(&fibonacci, first); 
        PrintInfo(fibonacci);
        return 0;
    } else {
		scanf("%d", &first);
		InsVLast(&fibonacci, first); 
		scanf("%d", &second);
		InsVLast(&fibonacci, second);
		
		el -= 2;
		
		for (i=0; i<el; i++) {
			next = first+second;
			InsVLast(&fibonacci, next); 
			first = second;
			second = next;
		}
		 
        PrintInfo(fibonacci);
    }

    return 0;
}
