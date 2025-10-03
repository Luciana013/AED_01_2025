#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0

typedef struct No {
    long long valor;
    struct No *proximo;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void remover(Pilha *pilha);
void criarPilha(Pilha *pilha);
long long obterMenor(Pilha *pilha);
void adicionar(Pilha *pilha, long long valor);

void main() {
    Pilha pilha;
    char operacao[10];
    unsigned numOperacoes;
    long long valor, menorValor;

    scanf("%u", &numOperacoes);

    criarPilha(&pilha);

    while (numOperacoes--) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%lld", &valor);
            adicionar(&pilha, valor);
        } else if (strcmp(operacao, "POP") == 0) {
            remover(&pilha);
        } else {
            menorValor = obterMenor(&pilha);
            if (menorValor == -1)
                printf("EMPTY\n");
            else
                printf("%lld\n", menorValor);
        }
    }
}

void criarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void adicionar(Pilha *pilha, long long valor) {
    No *novoNo;

    novoNo = (No *) malloc(sizeof(No));

    if (!novoNo)
        exit(1);

    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    novoNo->valor = valor;
}

void remover(Pilha *pilha) {
    No *temp;
    temp = pilha->topo;

    if (temp) {
        pilha->topo = temp->proximo;
        free(temp);
    } else {
        printf("EMPTY\n");
    }
}

long long obterMenor(Pilha *pilha) {
    No *atual;
    atual = pilha->topo;

    if (!atual)
        return -1;

    long long menor = atual->valor;

    while (atual) {
        if (atual->valor < menor)
            menor = atual->valor;

        atual = atual->proximo;
    }

    return menor;
}
