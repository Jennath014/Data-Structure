#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int visited[MAX]; // To track visited vertices

// Recursive DFS function
void DFS(int adj[MAX][MAX], int n, int start) {
    printf("%d ", start + 1); // Print current vertex
    visited[start] = 1;       // Mark as visited

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(adj, n, i); // Recursively visit the connected vertex
        }
    }
}

int main() {
    int n, start;
    int adj[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Input starting vertex
    printf("Enter the starting vertex (1 to %d): ", n);
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(adj, n, start - 1); // Adjust for 0-based indexing
    printf("\n");

    return 0;
}

