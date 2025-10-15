#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ------------------- Estrutura da pilha -------------------

typedef struct No {
    char dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

// ------------------- Operações básicas -------------------

void init(Pilha *p) {
    p->topo = NULL;
}

bool esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

bool push(Pilha *p, char c) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return false; // falha na alocação

    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pop(Pilha *p, char *c) {
    if (esta_vazia(p)) return false;

    No *temp = p->topo;
    *c = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return true;
}

void limpar_pilha(Pilha *p) {
    No *atual = p->topo;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    p->topo = NULL;
}

// ------------------- Verificação de balanceamento -------------------

void verifica_balanceamento(const char *expressao) {
    Pilha p;
    init(&p);
    bool valido = true;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char ch = expressao[i];

        if (ch == '(') {
            if (!push(&p, ch)) {
                valido = false;
                break;
            }
        } else if (ch == ')') {
            char descarte;
            if (!pop(&p, &descarte)) {
                valido = false;
                break;
            }
        }
    }

    if (!esta_vazia(&p)) {
        valido = false;
    }

    if (valido)
        printf("correct\n");
    else
        printf("incorrect\n");

    limpar_pilha(&p);
}

// ------------------- Função principal -------------------

int main(void) {
    char expressao[1001];

    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        size_t len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }

        verifica_balanceamento(expressao);
    }

    return 0;
}
