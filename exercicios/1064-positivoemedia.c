#include <stdio.h>

int main() {
    float num, soma = 0.0;
    int i, positivos = 0;

    for (i = 0; i < 6; i++) {
        scanf("%f", &num);

        if (num > 0) {
            soma += num;
            positivos++;
        }
    }

    printf("%d valores positivos\n", positivos);

    if (positivos > 0) {
        printf("%.1f\n", soma / positivos);
    }

    return 0;
}
