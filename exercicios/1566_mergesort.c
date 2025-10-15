#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort_recursive(int *arr, int *temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(arr, temp, left, mid);
        merge_sort_recursive(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void solve_1566_mergesort() {
    int NC; 
    
    if (scanf("%d", &NC) != 1) return;

    for (int c = 0; c < NC; ++c) {
        int N; 
        if (scanf("%d", &N) != 1) break;

        int *heights = (int *)malloc(N * sizeof(int));
        int *temp = (int *)malloc(N * sizeof(int));
        if (heights == NULL || temp == NULL) {
            free(heights); 
            free(temp); 
            return; 
        }

        for (int i = 0; i < N; ++i) {
            if (scanf("%d", &heights[i]) != 1) {
                free(heights); free(temp); 
                return;
            }
        }

        merge_sort_recursive(heights, temp, 0, N - 1);

        for (int i = 0; i < N; ++i) {
            printf("%d%s", heights[i], (i == N - 1) ? "" : " ");
        }
        printf("\n");

        free(heights);
        free(temp);
    }
}

int main() {
    solve_1566_mergesort();
    return 0;
}
