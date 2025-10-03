#include <stdio.h>

int main() {
    int N, k, m;

    while (1) {
        scanf("%d %d %d", &N, &k, &m);
        if (N == 0 && k == 0 && m == 0) break;

        int candidatos[20], i, j, count = 0;

        for (i = 1; i <= N; i++) candidatos[i] = 1;

        i = 1;
        j = N;

        while (count < N) {
            int ck = 0, cm = 0;

            while (ck < k) {
                if (candidatos[i]) ck++;
                if (ck < k) i = (i % N) + 1;
            }

            while (cm < m) {
                if (candidatos[j]) cm++;
                if (cm < m) j = (j - 2 + N) % N + 1;
            }

            printf("%3d", i);
            count++;
            candidatos[i] = 0;

            if (i != j) {
                printf("%3d", j);
                count++;
                candidatos[j] = 0;
            }

            if (count < N) printf(",");
        }

        printf("\n");
    }

    return 0;
}
