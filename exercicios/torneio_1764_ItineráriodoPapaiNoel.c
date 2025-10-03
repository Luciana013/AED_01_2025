#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_EDGES 40050
#define MAX_NODES 40000

typedef struct {
    int node1, node2, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_NODES];

int compare_edges(const void *, const void *);
int kruskal(int);
int find_set(int);

int main(int argc, char **argv)
{
    int num_nodes, num_edges, i;

    while (scanf("%d %d", &num_nodes, &num_edges), num_nodes && num_edges)
    {
        memset(edges, 0, sizeof(edges));
        memset(parent, 0, sizeof(parent));

        for (i = 0; i < num_edges; ++i)
            scanf("%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].weight);

        qsort(edges, num_edges, sizeof(Edge), compare_edges);

        for (i = 1; i <= num_nodes; ++i)
            parent[i] = i;

        printf("%d\n", kruskal(num_edges));
    }

    return 0;
}

int compare_edges(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find_set(int node)
{
    if (node == parent[node])
        return node;

    return find_set(parent[node]);
}

int kruskal(int num_edges)
{
    int i, total_weight = 0, set1, set2;

    for (i = 0; i < num_edges; ++i)
    {
        set1 = find_set(edges[i].node1);
        set2 = find_set(edges[i].node2);

        if (set1 != set2)
        {
            parent[set1] = set2;
            total_weight += edges[i].weight;
        }
    }

    return total_weight;
}
