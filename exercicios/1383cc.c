#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
    p->capacidade = 1;
    p->dados = (int *)malloc(p->capacidade * sizeof(int));
    if (p->dados == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
}

void liberar(Pilha *p) {
    free(p->dados);
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void redimensionar(Pilha *p) {
    p->capacidade *= 2;
    p->dados = (int *)realloc(p->dados, p->capacidade * sizeof(int));
    if (p->dados == NULL) {
        printf("Erro de realocação de memória!\n");
        exit(1);
    }
}

void push(Pilha *p, int valor) {
    if (p->topo + 1 >= p->capacidade)
        redimensionar(p);
    p->dados[++p->topo] = valor;
}

int contem(Pilha *p, int valor) {
    for (int i = 0; i <= p->topo; i++)
        if (p->dados[i] == valor)
            return 1;
    return 0;
}

int aferir(int vetor[]) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; i < 9; i++) {
        int valor = vetor[i];
        if (valor < 1 || valor > 9) {
            liberar(&p);
            return 0;
        }
        if (contem(&p, valor)) {
            liberar(&p);
            return 0;
        }
        push(&p, valor);
    }

    liberar(&p);
    return 1;
}

int aferir_sudoku(int matriz[][9]) {
    // Verifica linhas
    for (int i = 0; i < 9; i++) {
        if (!aferir(matriz[i]))
            return 0;
    }

    // Verifica colunas
    for (int j = 0; j < 9; j++) {
        int coluna[9];
        for (int i = 0; i < 9; i++)
            coluna[i] = matriz[i][j];
        if (!aferir(coluna))
            return 0;
    }

    // Verifica regiões 3x3
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int regiao[9];
            int index = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    regiao[index++] = matriz[x][y];
                }
            }
            if (!aferir(regiao))
                return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int matriz[9][9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &matriz[i][j]);

        printf("Instancia %d\n", instancia);
        if (aferir_sudoku(matriz))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
    }

    return 0;
}
