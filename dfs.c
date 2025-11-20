#include <stdio.h>

#define MAX 10  // Maximum number of vertices

int visited[MAX];          // Array to track visited vertices
int adj[MAX][MAX];         // Adjacency matrix
int n;                     // Number of vertices

// Function to perform DFS
void DFS(int vertex) {
    printf("%d ", vertex);  // Print the current vertex
    visited[vertex] = 1;    // Mark it as visited

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i);  // Recursive call for connected vertex
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(start);

    return 0;
}

