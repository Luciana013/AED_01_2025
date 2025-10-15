#include "stdio.h"

#define MAX 100

typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

void push(Pilha* pilha, int valor) {
    if (pilha->topo < MAX - 1) {
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
}

int pop(Pilha* pilha) {
    if (!pilhaVazia(pilha)) {
        int valor = pilha->elementos[pilha->topo];
        pilha->topo--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

int main() {
    int n, valor, menor, posicao;
    Pilha pilha;
    inicializarPilha(&pilha);

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        push(&pilha, valor);
    }

    menor = pilha.elementos[0];
    posicao = 0;

    for (int i = 1; i < n; i++) {
        int elementoAtual = pilha.elementos[i];
        if (elementoAtual < menor) {
            menor = elementoAtual;
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
