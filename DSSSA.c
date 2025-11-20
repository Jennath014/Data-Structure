#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 9999  // Represent infinity

int graph[MAX][MAX], distance[MAX], visited[MAX];
int n; // number of vertices

// Function to find the vertex with the minimum distance
int findMinVertex() {
    int min = INF, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(int src) {
    // Step 1: Initialize
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[src] = 0;

    // Step 2: Process each vertex
    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex();
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && graph[u][v] != INF) {
                if (distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Display result
    printf("\nVertex\tDistance from Source (%d)\n", src + 1);
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i + 1, distance[i]);
    }
}

int main() {
    int src;

    // Input graph
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix (9999 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input source vertex
    printf("Enter the source vertex (1 to %d): ", n);
    scanf("%d", &src);

    // Run Dijkstra's Algorithm
    dijkstra(src - 1);

    return 0;
}

