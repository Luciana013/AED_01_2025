#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void solve_1566_selection() {
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

        selection_sort(heights, N);

        for (int i = 0; i < N; ++i) {
            printf("%d%s", heights[i], (i == N - 1) ? "" : " ");
        }
        printf("\n");

        free(heights);
    }
}

int main() {
    solve_1566_selection();
    return 0;
}
