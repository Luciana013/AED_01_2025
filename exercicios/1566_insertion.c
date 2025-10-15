#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void solve_1566_insertion() {
    int NC; 
    
    if (scanf("%d", &NC) != 1) return;

    for (int c = 0; c < NC; ++c) {
        int N; 
        if (scanf("%d", &N) != 1) break;

        int *heights = (int *)malloc(N * sizeof(int));
        if (heights == NULL) return;

        for (int i = 0; i < N; ++i) {
            if (scanf("%d", &heights[i]) != 1) {
                free(heights);
                return;
            }
        }

        insertion_sort(heights, N);

        for (int i = 0; i < N; ++i) {
            printf("%d%s", heights[i], (i == N - 1) ? "" : " ");
        }
        printf("\n");

        free(heights);
    }
}

int main() {
    solve_1566_insertion();
    return 0;
}
