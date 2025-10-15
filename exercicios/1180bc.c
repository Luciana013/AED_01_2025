#include "stdio.h"

#define MAX 100  // Tamanho máximo da pilha

typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

// Função para adicionar um elemento na pilha
void push(Pilha* pilha, int valor) {
    if (pilha->topo < MAX - 1) {
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
}

// Função para remover um elemento da pilha
int pop(Pilha* pilha) {
    if (!pilhaVazia(pilha)) {
        int valor = pilha->elementos[pilha->topo];
        pilha->topo--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;  // Retorna um valor inválido
    }
}

int main() {
    int n, valor, menor, posicao;
    Pilha pilha;
    inicializarPilha(&pilha);

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Lê os elementos e empilha
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        push(&pilha, valor);
    }

    // Inicializa menor e posição com o primeiro elemento da pilha
    menor = pilha.elementos[0];
    posicao = 0;

    // Verifica o menor valor e sua posição
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
