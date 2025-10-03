#include <stdio.h>

int main() {
    int inicio, fim;
    scanf("%d %d", &inicio, &fim);

    int duracao;
    if (inicio < fim) {
        duracao = fim - inicio;
    } else {
        duracao = (24 - inicio) + fim;
    }

    printf("O JOGO DUROU %d HORA(S)\n", duracao);

    return 0;
}
