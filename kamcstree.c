#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX];

// Structure to represent a subset for Disjoint Set
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a node (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to union two sets (by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges by weight for qsort
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's Algorithm
void kruskal(int n, int e) {
    struct Edge result[MAX];  // Store MST edges
    int i = 0, j = 0;
    int totalCost = 0;

    // Step 1: Sort all edges by weight
    qsort(edges, e, sizeof(edges[0]), compareEdges);

    // Step 2: Create subsets
    struct Subset *subsets = (struct Subset*)malloc(n * sizeof(struct Subset));
    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 3: Pick the smallest edge and check for cycle
    while (i < n - 1 && j < e) {
        struct Edge nextEdge = edges[j++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does NOT cause a cycle
        if (x != y) {
            result[i++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Display the Minimum Cost Spanning Tree
    printf("\nEdges in the Minimum Cost Spanning Tree:\n");
    for (int k = 0; k < i; k++) {
        printf("%d - %d : %d\n", result[k].src + 1, result[k].dest + 1, result[k].weight);
        totalCost += result[k].weight;
    }

    printf("\nTotal Minimum Cost of Spanning Tree: %d\n", totalCost);

    free(subsets);
}

int main() {
    int n, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edges[i].src--;  // Convert to 0-based index
        edges[i].dest--;
    }

    kruskal(n, e);

    return 0;
}

