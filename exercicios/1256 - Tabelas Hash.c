#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* proximo;
} No;

void inserir(No** tabelaHash, int indice, int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->proximo = NULL;

    if (tabelaHash[indice] == NULL) {
        tabelaHash[indice] = novoNo;
    } else {
        No* atual = tabelaHash[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void imprimirTabelaHash(No** tabelaHash, int M) {
    for (int i = 0; i < M; i++) {
        printf("%d ->", i);
        No* atual = tabelaHash[i];
        while (atual != NULL) {
            printf(" %d ->", atual->chave);
            atual = atual->proximo;
        }
        printf(" \\\n");
    }
}

void liberarTabelaHash(No** tabelaHash, int M) {
    for (int i = 0; i < M; i++) {
        No* atual = tabelaHash[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int casoTeste = 0; casoTeste < N; casoTeste++) {
        int M, C;
        scanf("%d %d", &M, &C);

        No** tabelaHash = (No**)calloc(M, sizeof(No*));

        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            int indice = chave % M;
            inserir(tabelaHash, indice, chave);
        }

        imprimirTabelaHash(tabelaHash, M);

        if (casoTeste < N - 1) {
            printf("\n");
        }

        liberarTabelaHash(tabelaHash, M);
        free(tabelaHash);
    }

    return 0;
}
