#include <stdio.h>
#include <string.h>

typedef struct{
	char str[200];
} cadeia;

char frase[10050];
cadeia paragrafo[10050];
cadeia alvo[200];

#define verdadeiro 1
#define falso 0

int main(int argc, char **argv)
{
	char temp[10050], *aux;
	unsigned n, i, j, k;

	scanf(" %[^\n]", temp);
	scanf("%*c%u", &n);

	for (i = 0; i < n; ++i)
		scanf("%s", alvo[i].str);

	i = 0;
	aux = strtok(temp, " ");
	strcpy(paragrafo[i++].str, aux);

	do
	{
		aux = strtok(0, " ");
		if (aux)
			strcpy(paragrafo[i++].str, aux);

	} while (aux);

	for (k = 0; k < n; ++k)
	{
		unsigned tamanho = 0;
		_Bool encontrado = verdadeiro;

		for (j = 0; j < i; ++j)
		{
			if (strcmp(paragrafo[j].str, alvo[k].str) == 0)
				if (!encontrado)
					printf(" %u", tamanho);
				else
					printf("%u", tamanho), encontrado = falso;

			tamanho += strlen(paragrafo[j].str) + 1;
		}

		if (encontrado)
			printf("-1\n");
		else
			printf("\n");
	}

	return 0;
}
