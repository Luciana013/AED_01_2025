#include <stdio.h>

int main() {
    int a, b, c;
    int sorted[3];

    scanf("%d %d %d", &a, &b, &c);

    sorted[0] = a;
    sorted[1] = b;
    sorted[2] = c;

    if (sorted[0] > sorted[1]) {
        int temp = sorted[0];
        sorted[0] = sorted[1];
        sorted[1] = temp;
    }
    if (sorted[1] > sorted[2]) {
        int temp = sorted[1];
        sorted[1] = sorted[2];
        sorted[2] = temp;
    }
    if (sorted[0] > sorted[1]) {
        int temp = sorted[0];
        sorted[0] = sorted[1];
        sorted[1] = temp;
    }

    printf("%d\n%d\n%d\n", sorted[0], sorted[1], sorted[2]);
    printf("\n");
    printf("%d\n%d\n%d\n", a, b, c);

    return 0;
}
