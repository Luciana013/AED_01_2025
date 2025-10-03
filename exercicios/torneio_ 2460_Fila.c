#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned short numero;
    unsigned short posicao;
} pessoa;

int main() {
    unsigned short qtsPessoas, qtsPessoasSairam;
    unsigned short i, idPessoa;

    scanf("%hu", &qtsPessoas);

    pessoa fila[51000];
    bool primEspaco = false;

    for (i = 0; i < qtsPessoas; i++) {
        scanf("%hu", &idPessoa);
        fila[i].numero = idPessoa;
        fila[idPessoa].posicao = i;
    }

    scanf("%hu", &qtsPessoasSairam);

    for (i = 0; i < qtsPessoasSairam; i++) {
        scanf("%hu", &idPessoa);
        fila[fila[idPessoa].posicao].numero = 0;
    }

    for (i = 0; i < qtsPessoas; i++) {
        if (fila[i].numero != 0) {
            if (primEspaco) {
                printf(" ");
            }
            printf("%hu", fila[i].numero);
            primEspaco = true;
        }
    }

    printf("\n");

    return 0;
}
