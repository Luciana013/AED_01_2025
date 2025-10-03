#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int K;
        scanf("%d", &K);

        char idiomas[K][21];
        for (int i = 0; i < K; i++) {
            scanf("%s", idiomas[i]);
        }

        int todosIguais = 1;
        for (int i = 1; i < K; i++) {
            if (strcmp(idiomas[0], idiomas[i]) != 0) {
                todosIguais = 0;
                break;
            }
        }

        if (todosIguais) {
            printf("%s\n", idiomas[0]);
        } else {
            printf("ingles\n");
        }
    }
    
    return 0;
}
