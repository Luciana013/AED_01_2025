#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000  // tamanho máximo da expressão

typedef struct {
    char dados[MAX];
    int topo; // índice do topo (último elemento)
} Pilha;

void init(Pilha *p) {
    p->topo = -1;
}

bool esta_vazia(Pilha *p) {
    return p->topo == -1;
}

bool esta_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

bool push(Pilha *p, char c) {
    if (esta_cheia(p)) return false;
    p->dados[++(p->topo)] = c;
    return true;
}

bool pop(Pilha *p, char *c) {
    if (esta_vazia(p)) return false;
    *c = p->dados[(p->topo)--];
    return true;
}

void verifica_balanceamento(const char *expressao) {
    Pilha p;
    init(&p);
    bool valido = true;
    int i;

    for (i = 0; expressao[i] != '\0'; i++) {
        char ch = expressao[i];

        if (ch == '(') {
            if (!push(&p, ch)) { // pilha cheia (não esperado para entradas pequenas)
                valido = false;
                break;
            }
        } else if (ch == ')') {
            char descarte;
            if (!pop(&p, &descarte)) { // tenta tirar mas está vazia -> parêntese fechado sem aberto
                valido = false;
                break;
            }
        }
        // outros caracteres são ignorados
    }

    if (!esta_vazia(&p)) { // sobram '(' então inválido
        valido = false;
    }

    if (valido) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }
}

int main(void) {
    char expressao[MAX + 1];

    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        size_t len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }

        verifica_balanceamento(expressao);
    }

    return 0;
}
