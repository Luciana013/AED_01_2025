#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INFINITO 100000
#define TAMANHO_MAX 101010

int visitado[TAMANHO_MAX];
int distancia[TAMANHO_MAX];

typedef struct _no {
    int vertice, peso;
    struct _no *proximo;
} no_t;

typedef struct _grafo {
    no_t *adjacente;
} grafo_t;

grafo_t *criar_grafo(int);
no_t *criar_no(int, int);
void dijkstra(grafo_t *, int, int);
void adicionar_aresta(grafo_t *, int, int, int);

int main(int argc, char **argv) {
    int i;
    int num_vertices, num_arestas, limite, inicial, vertice_a, vertice_b, peso;

    while (scanf("%d %d %d %d", &num_vertices, &num_arestas, &limite, &inicial), (limite && num_vertices && num_arestas && inicial)) {    
        grafo_t *grafo = criar_grafo(num_vertices + 1);

        for (i = 0; i < num_arestas; ++i) {
            scanf("%d %d %d", &vertice_a, &vertice_b, &peso);

            if (vertice_a >= limite && vertice_b >= limite || ((vertice_a < limite) && (vertice_b < limite) && (abs(vertice_a - vertice_b) == 1)))
                adicionar_aresta(grafo, vertice_a, vertice_b, peso), adicionar_aresta(grafo, vertice_b, vertice_a, peso);

            if (vertice_a >= limite && vertice_b < limite)
                adicionar_aresta(grafo, vertice_b, vertice_a, peso);

            if (vertice_b >= limite && vertice_a < limite)
                adicionar_aresta(grafo, vertice_a, vertice_b, peso);
        }

        dijkstra(grafo, inicial, num_vertices);
        printf("%d\n", distancia[limite - 1]);
    }

    return 0;
}

void dijkstra(grafo_t *g, int s, int tamanho) {
    no_t *k;
    int i, j, v;

    for (i = 0; i < tamanho; ++i)
        distancia[i] = INFINITO;

    memset(visitado, false, sizeof(visitado));

    distancia[s] = 0;

    for (i = 0; i < tamanho; ++i) {
        v = -1;

        for (j = 0; j < tamanho; ++j)
            if (!visitado[j] && (v == -1 || distancia[j] < distancia[v]))
                v = j;

        if (distancia[v] == INFINITO)
            break;

        visitado[v] = true;

        for (k = g->adjacente[v].proximo; k != NULL; k = k->proximo) {
            int para = k->vertice;
            int len = k->peso;

            if (distancia[v] + len < distancia[para])
                distancia[para] = distancia[v] + len;
        }
    }
}

grafo_t *criar_grafo(int tamanho) {
    int i;
    grafo_t *g = (grafo_t *)malloc(sizeof(grafo_t));
    g->adjacente = (no_t *)malloc(sizeof(no_t) * (tamanho + 1));

    for (i = 0; i < tamanho; ++i)
        g->adjacente[i].proximo = NULL;

    return g;
}

no_t *criar_no(int vertice, int peso) {
    no_t *novo_no = (no_t *)malloc(sizeof(no_t));
    novo_no->vertice = vertice;
    novo_no->peso = peso;
    novo_no->proximo = NULL;
    return novo_no;
}

void adicionar_aresta(grafo_t *g, int u, int v, int w) {
    no_t *novo_no = criar_no(u, w);
    novo_no->proximo = g->adjacente[v].proximo;
    g->adjacente[v].proximo = novo_no;
}
