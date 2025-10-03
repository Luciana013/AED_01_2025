#include <stdio.h>

int N, P;
int black[502][502], white[502][502], sum[502][502];

void preprocess(int arr[502][502]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
}

int query(int arr[502][502], int x1, int y1, int x2, int y2) {
    return arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
}

int main() {
    scanf("%d %d", &N, &P);
    
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        black[L][C] = 1;
    }

    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        white[L][C] = 1;
    }

    preprocess(black);
    preprocess(white);

    int black_count = 0, white_count = 0;

    for (int size = 1; size <= N; size++) {
        for (int i = 1; i <= N - size + 1; i++) {
            for (int j = 1; j <= N - size + 1; j++) {
                int x2 = i + size - 1;
                int y2 = j + size - 1;
                
                int b_count = query(black, i, j, x2, y2);
                int w_count = query(white, i, j, x2, y2);
                
                if (b_count > 0 && w_count == 0) black_count++;
                if (w_count > 0 && b_count == 0) white_count++;
            }
        }
    }

    printf("%d %d\n", black_count, white_count);

    return 0;
}
