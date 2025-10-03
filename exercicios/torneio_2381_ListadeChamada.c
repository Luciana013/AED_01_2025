#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX_NOME 21
#define MAX_ALUNOS 100

typedef struct {
    char nome[TAMANHO_MAX_NOME];
} Aluno;

void insertionSort(Aluno alunos[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        Aluno chave = alunos[i];
        int j = i - 1;
        while (j >= 0 && strcmp(alunos[j].nome, chave.nome) > 0) {
            alunos[j + 1] = alunos[j];
            j--;
        }
        alunos[j + 1] = chave;
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int tamanho, alunoVencedor;

    scanf("%d %d", &tamanho, &alunoVencedor);

    for (int i = 0; i < tamanho; i++) {
        scanf("%s", alunos[i].nome);
    }

    insertionSort(alunos, tamanho);
    printf("%s\n", alunos[alunoVencedor - 1].nome);

    return 0;
}
