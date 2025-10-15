#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_HEIGHT 20
#define MAX_HEIGHT 230
#define RANGE (MAX_HEIGHT - MIN_HEIGHT + 1)

void solve_1566_counting() {
    int count[RANGE];
    int NC; 
    
    if (scanf("%d", &NC) != 1) return;

    for (int c = 0; c < NC; ++c) {
        int N; 
        if (scanf("%d", &N) != 1) break;

        memset(count, 0, sizeof(count));

        for (int i = 0; i < N; ++i) {
            int h;
            if (scanf("%d", &h) != 1) break;
            count[h - MIN_HEIGHT]++;
        }

        int first = 1;

        for (int h_idx = 0; h_idx < RANGE; ++h_idx) {
            int current_height = MIN_HEIGHT + h_idx;
            int frequency = count[h_idx];

            for (int k = 0; k < frequency; ++k) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", current_height);
                first = 0; 
            }
        }
        printf("\n");
    }
}

int main() {
    solve_1566_counting();
    return 0;
}
