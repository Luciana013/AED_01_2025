#include <stdio.h>
#include <stdlib.h>

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        int count[231] = {0}; // alturas de 20 a 230

        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            count[h]++;
        }

        int first = 1;
        for (int h = 20; h <= 230; h++) {
            while (count[h]--) {
                if (!first) printf(" ");
                printf("%d", h);
                first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}
