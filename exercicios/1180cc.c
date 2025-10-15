#include "stdio.h"
#include "stdlib.h"

typedef struct Nodo {
    int valor;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo* topo;
} Pilha;

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void push(Pilha* pilha, int valor) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);  // Caso ocorra erro de alocação
    }
    novoNodo->valor = valor;
    novoNodo->proximo = pilha->topo;
    pilha->topo = novoNodo;
}

int pop(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    Nodo* nodoRemovido = pilha->topo;
    int valor = nodoRemovido->valor;
    pilha->topo = pilha->topo->proximo;
    free(nodoRemovido);
    return valor;
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

    Nodo* temp = pilha.topo;
    menor = temp->valor;
    posicao = 0;
    int indice = 0;
    temp = temp->proximo;

    while (temp != NULL) {
        indice++;
        if (temp->valor < menor) {
            menor = temp->valor;
            posicao = indice;
        }
        temp = temp->proximo;
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
