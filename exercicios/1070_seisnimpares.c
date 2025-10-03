#include <stdio.h>

int main() {
    int X, count = 0;

    scanf("%d", &X);

    while (count < 6) {
        if (X % 2 != 0) { 
            printf("%d\n", X);
            count++;
        }
        X++;
    }

    return 0;
}
