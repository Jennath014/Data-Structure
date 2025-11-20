#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];    // Adjacency matrix
int indegree[MAX];    // Array to store indegree of each vertex
int queue[MAX], front = 0, rear = -1;

// Enqueue operation
void enqueue(int vertex) {
    rear++;
    queue[rear] = vertex;
}

// Dequeue operation
int dequeue() {
    return queue[front++];
}

// Function to perform Topological Sort using Kahn's Algorithm
void topologicalSort(int n) {
    int count = 0;
    int topoOrder[MAX];

    // Step 1: Compute indegree of each vertex
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Enqueue all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    // Step 3: Process vertices
    while (front <= rear) {
        int u = dequeue();
        topoOrder[count++] = u;

        // For every adjacent vertex, decrease indegree
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;

                // If indegree becomes 0, enqueue it
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // Step 4: Check if topological sort is possible
    if (count != n) {
        printf("Graph has a cycle! Topological sort not possible.\n");
        return;
    }

    // Step 5: Print topological order
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topoOrder[i] + 1); // +1 for human-friendly numbering
    }
    printf("\n");
}

int main() {
    int n;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n);

    return 0;
}

