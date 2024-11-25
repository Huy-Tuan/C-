#include <stdio.h>

int main() {
    for (int number = 1; number <= 9; number++) {
        printf("Bang cuu chuong cua %d:\n", number);
        
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", number, i, number * i);
        }
        
        printf("\n");
    }

    return 0;
}
