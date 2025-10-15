#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int temp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void solve_1566_quick() {
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

        quick_sort(heights, 0, N - 1);

        for (int i = 0; i < N; ++i) {
            printf("%d%s", heights[i], (i == N - 1) ? "" : " ");
        }
        printf("\n");

        free(heights);
    }
}

int main() {
    solve_1566_quick();
    return 0;
}
