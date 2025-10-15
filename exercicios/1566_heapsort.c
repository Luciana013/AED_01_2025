#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    int temp;
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void solve_1566_heapsort() {
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

        heap_sort(heights, N);

        for (int i = 0; i < N; ++i) {
            printf("%d%s", heights[i], (i == N - 1) ? "" : " ");
        }
        printf("\n");

        free(heights);
    }
}

int main() {
    solve_1566_heapsort();
    return 0;
}
