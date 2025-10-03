#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
} Pessoa;

void ordenar(Pessoa *, unsigned short tam);

int main() {
    unsigned short i;
    unsigned short totalAlunos, posicaoPremiada;

    scanf("%hu %hu", &totalAlunos, &posicaoPremiada);
    Pessoa listaAlunos[totalAlunos];

    for (i = 0; i < totalAlunos; i++) {
        scanf("%s", listaAlunos[i].nome);
    }

    ordenar(listaAlunos, totalAlunos);
    
    printf("%s\n", listaAlunos[posicaoPremiada - 1].nome);

    return 0;
}

void ordenar(Pessoa *listaAlunos, unsigned short tam) {
    short i = 1, j;
    Pessoa pivo;

    while (i < tam) {
        j = i - 1;
        pivo = listaAlunos[i];

        while (j >= 0 && strcmp(listaAlunos[j].nome, pivo.nome) > 0) {
            listaAlunos[j + 1] = listaAlunos[j];
            j--;
        }

        listaAlunos[j + 1] = pivo;
        i++;
    }
}
