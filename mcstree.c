#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 9999

int cost[MAX][MAX], visited[MAX], n;

// Function to find the vertex with minimum key value
int findMinVertex(int key[], int visited[]) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim's Algorithm to find Minimum Cost Spanning Tree
void primsAlgorithm() {
    int parent[MAX], key[MAX];
    int totalCost = 0;

    // Initialize all keys as infinity and visited[] as 0
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(key, visited);
        visited[u] = 1;

        // Update the key and parent index of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !visited[v] && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    // Print the Minimum Cost Spanning Tree
    printf("\nEdges in Minimum Cost Spanning Tree:\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d  : %d\n", parent[i] + 1, i + 1, cost[i][parent[i]]);
        totalCost += cost[i][parent[i]];
    }

    printf("\nTotal Minimum Cost of Spanning Tree: %d\n", totalCost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF; // No edge between i and j
        }
    }

    primsAlgorithm();
    return 0;
}

