#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v, w, p;
} Edge;

int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->p - edgeB->p;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int kruskalMST(Edge edges[], int R, int C) {
    qsort(edges, C, sizeof(Edge), compare);

    int *parent = (int *)malloc(R * sizeof(int));
    int *rank = (int *)malloc(R * sizeof(int));
    for (int i = 0; i < R; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstCost = 0;
    int edgesUsed = 0;

    for (int i = 0; i < C; i++) {
        int rootV = find(parent, edges[i].v - 1);
        int rootW = find(parent, edges[i].w - 1);

        if (rootV != rootW) {
            mstCost += edges[i].p;
            unionSets(parent, rank, rootV, rootW);
            edgesUsed++;

            if (edgesUsed == R - 1)
                break;
        }
    }

    free(parent);
    free(rank);

    return mstCost;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    Edge *edges = (Edge *)malloc(C * sizeof(Edge));

    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &edges[i].v, &edges[i].w, &edges[i].p);
    }

    int result = kruskalMST(edges, R, C);
    printf("%d\n", result);

    free(edges);
    return 0;
}
