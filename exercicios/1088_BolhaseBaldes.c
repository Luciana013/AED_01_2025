#include <stdio.h>
#include <stdlib.h>

int merge_and_count(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
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

    return inv_count;
}

int merge_sort_and_count(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = left + (right - left) / 2;

        inv_count += merge_sort_and_count(arr, temp, left, mid);
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right);
        inv_count += merge_and_count(arr, temp, left, mid, right);
    }
    return inv_count;
}

int count_inversions(int arr[], int n) {
    int *temp = (int *)malloc(n * sizeof(int));
    int inv_count = merge_sort_and_count(arr, temp, 0, n - 1);
    free(temp);
    return inv_count;
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        int *arr = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int inv_count = count_inversions(arr, N);
        if (inv_count % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }

        free(arr);
    }
    return 0;
}
