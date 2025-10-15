#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// ---------- PILHA ----------
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void pilha_inicializa(Pilha *p) { p->topo = -1; }
bool pilha_vazia(Pilha *p) { return p->topo == -1; }
bool pilha_push(Pilha *p, int x) {
    if (p->topo == MAX - 1) return false;
    p->dados[++p->topo] = x;
    return true;
}
bool pilha_pop(Pilha *p, int *x) {
    if (pilha_vazia(p)) return false;
    *x = p->dados[p->topo--];
    return true;
}

// ---------- FILA ----------
typedef struct {
    int dados[MAX];
    int ini, fim;
} Fila;

void fila_inicializa(Fila *f) { f->ini = f->fim = 0; }
bool fila_vazia(Fila *f) { return f->ini == f->fim; }
bool fila_push(Fila *f, int x) {
    if (f->fim == MAX) return false;
    f->dados[f->fim++] = x;
    return true;
}
bool fila_pop(Fila *f, int *x) {
    if (fila_vazia(f)) return false;
    *x = f->dados[f->ini++];
    return true;
}

// ---------- FILA DE PRIORIDADE ----------
typedef struct {
    int dados[MAX];
    int tamanho;
} FilaPrioridade;

void fp_inicializa(FilaPrioridade *fp) { fp->tamanho = 0; }
bool fp_vazia(FilaPrioridade *fp) { return fp->tamanho == 0; }
bool fp_push(FilaPrioridade *fp, int x) {
    if (fp->tamanho == MAX) return false;
    fp->dados[fp->tamanho++] = x;
    return true;
}
bool fp_pop(FilaPrioridade *fp, int *x) {
    if (fp_vazia(fp)) return false;
    int i, maior = 0;
    for (i = 1; i < fp->tamanho; i++) {
        if (fp->dados[i] > fp->dados[maior])
            maior = i;
    }
    *x = fp->dados[maior];
    fp->dados[maior] = fp->dados[--fp->tamanho];
    return true;
}

// ---------- PRINCIPAL ----------
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Pilha pilha; Fila fila; FilaPrioridade fp;
        pilha_inicializa(&pilha);
        fila_inicializa(&fila);
        fp_inicializa(&fp);

        bool e_pilha = true, e_fila = true, e_fp = true;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) { // inserção
                pilha_push(&pilha, x);
                fila_push(&fila, x);
                fp_push(&fp, x);
            } else if (op == 2) { // remoção
                int y;

                if (!pilha_pop(&pilha, &y) || y != x)
                    e_pilha = false;

                if (!fila_pop(&fila, &y) || y != x)
                    e_fila = false;

                if (!fp_pop(&fp, &y) || y != x)
                    e_fp = false;
            }
        }

        if ((e_pilha && e_fila) || (e_pilha && e_fp) || (e_fila && e_fp))
            printf("not sure\n");
        else if (e_pilha)
            printf("stack\n");
        else if (e_fila)
            printf("queue\n");
        else if (e_fp)
            printf("priority queue\n");
        else
            printf("impossible\n");
    }

    return 0;
}
