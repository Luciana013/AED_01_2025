#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void verifica_balanceamento(const char *expressao) {
    int contador = 0; 
    bool valido = true; 
    int i;

    for (i = 0; expressao[i] != '\0'; i++) {
        char caractere = expressao[i];

        if (caractere == '(') {
            contador++;
        } else if (caractere == ')') {
            contador--;
        }

        if (contador < 0) {
            valido = false;
            break; 
        }
    }

    if (contador != 0) {
        valido = false;
    }

    if (valido) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }
}

int main() {
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
