#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF 0x3f3f3f3f

typedef struct {
    int cidade;
    int custo;
} Aresta;

typedef struct {
    Aresta *arestas;
    int num_arestas;
} Grafo;

Grafo *grafo;
int n, m;

void init() {
    grafo = (Grafo *)malloc((n + 1) * sizeof(Grafo));
    for (int i = 1; i <= n; i++) {
        grafo[i].arestas = (Aresta *)malloc(100 * sizeof(Aresta));
        grafo[i].num_arestas = 0;
    }
}

void add_edge(int u, int v, int c) {
    grafo[u].arestas[grafo[u].num_arestas].cidade = v;
    grafo[u].arestas[grafo[u].num_arestas].custo = c;
    grafo[u].num_arestas++;

    grafo[v].arestas[grafo[v].num_arestas].cidade = u;
    grafo[v].arestas[grafo[v].num_arestas].custo = c;
    grafo[v].num_arestas++;
}

typedef struct {
    int custo, cidade, estado;
} Node;

typedef struct {
    Node *heap;
    int tamanho, capacidade;
} MinHeap;

MinHeap* cria_heap(int capacidade) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacidade = capacidade;
    heap->tamanho = 0;
    heap->heap = (Node*)malloc(capacidade * sizeof(Node));
    return heap;
}

void troca(MinHeap *heap, int i, int j) {
    Node temp = heap->heap[i];
    heap->heap[i] = heap->heap[j];
    heap->heap[j] = temp;
}

void heapify(MinHeap *heap, int i) {
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < heap->tamanho && heap->heap[esquerda].custo < heap->heap[menor].custo)
        menor = esquerda;
    if (direita < heap->tamanho && heap->heap[direita].custo < heap->heap[menor].custo)
        menor = direita;

    if (menor != i) {
        troca(heap, i, menor);
        heapify(heap, menor);
    }
}

Node extrai_min(MinHeap *heap) {
    if (heap->tamanho == 0) {
        Node n = {-1, INF, INF};
        return n;
    }

    Node raiz = heap->heap[0];
    heap->heap[0] = heap->heap[heap->tamanho - 1];
    heap->tamanho--;
    heapify(heap, 0);
    return raiz;
}

void insere(MinHeap *heap, Node nodo) {
    if (heap->tamanho == heap->capacidade) {
        heap->capacidade *= 2;
        heap->heap = (Node*)realloc(heap->heap, heap->capacidade * sizeof(Node));
    }

    heap->heap[heap->tamanho++] = nodo;
    int i = heap->tamanho - 1;
    while (i && heap->heap[(i - 1) / 2].custo > heap->heap[i].custo) {
        troca(heap, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int dijkstra(int start, int end) {
    bool used[n + 1][2];
    int dists[n + 1][2];

    for (int i = 1; i <= n; i++) {
        used[i][0] = used[i][1] = false;
        dists[i][0] = dists[i][1] = INF;
    }

    dists[start][0] = 0;
    dists[start][1] = 0;

    MinHeap *heap = cria_heap(n);
    insere(heap, (Node){0, start, 0});

    while (heap->tamanho > 0) {
        Node u = extrai_min(heap);
        int custo = u.custo;
        int cidade = u.cidade;
        int estado = u.estado;

        if (used[cidade][estado]) continue;
        used[cidade][estado] = true;

        for (int i = 0; i < grafo[cidade].num_arestas; i++) {
            Aresta aresta = grafo[cidade].arestas[i];
            int v = aresta.cidade;
            int wei = aresta.custo;
            int novo_custo = custo + wei;
            int novo_estado = 1 - estado;

            if (dists[v][novo_estado] > novo_custo) {
                dists[v][novo_estado] = novo_custo;
                insere(heap, (Node){novo_custo, v, novo_estado});
            }
        }
    }

    int resposta = dists[end][0];
    free(heap->heap);
    free(heap);

    return (resposta == INF) ? -1 : resposta;
}

int main() {
    scanf("%d %d", &n, &m);
    init();

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        add_edge(u, v, c);
    }

    printf("%d\n", dijkstra(1, n));

    for (int i = 1; i <= n; i++) {
        free(grafo[i].arestas);
    }
    free(grafo);
    return 0;
}
