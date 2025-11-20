#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w; // edge from u to v with weight w
} Edge;

int parent[MAX];

// Disjoint Set functions
void makeSet(int n) {
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]); // path compression
    return parent[x];
}

void unionSets(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px != py)
        parent[px] = py;
}

// Compare function for qsort (sort by weight)
int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    Edge edges[e];
    printf("Enter edges (u v weight):\n");
    for(int i=0; i<e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), cmp);

    makeSet(n);

    int mstWeight = 0;
    printf("Edges in MST:\n");
    for(int i=0; i<e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if(find(u) != find(v)) {
            printf("%d-%d (weight %d)\n", u, v, edges[i].w);
            mstWeight += edges[i].w;
            unionSets(u, v);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
    return 0;
}

