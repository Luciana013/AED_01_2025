#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef unsigned short ushort;

ushort contar_diamantes(char *);

int main() {
    ushort total_testes;
    int descarte;
    char expressao[1005];

    scanf("%hu", &total_testes);
    scanf("%d", &descarte);

    while (total_testes--) {
        fgets(expressao, 1005, stdin);
        expressao[strlen(expressao) - 1] = '\0';
        printf("%hu\n", contar_diamantes(expressao));
        memset(expressao, 0, sizeof(expressao));
    }

    return 0;
}

ushort contar_diamantes(char *expressao) {
    short pos = 0;
    ushort total_diamantes = 0;

    ushort i, j;
    for (i = 0; expressao[i]; ++i) {
        if (expressao[i] != '<')
            continue;

        for (j = i + 1; expressao[j]; ++j) {
            if (expressao[j] == '>') {
                ++total_diamantes;
                expressao[i] = 'x';
                expressao[j] = 'x';
                break;
            }
        }
    }

    return total_diamantes;
}
