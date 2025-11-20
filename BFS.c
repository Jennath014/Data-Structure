#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX]; // To track visited vertices

// Enqueue operation
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) // First element
        front = 0;
    rear++;
    queue[rear] = vertex;
}

// Dequeue operation
int dequeue() {
    if (front == -1 || front > rear) {
        return -1; // Queue is empty
    }
    return queue[front++];
}

// BFS function
void BFS(int adj[MAX][MAX], int n, int start) {
    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start BFS
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start + 1);

    while (front != -1 && front <= rear) {
        int current = dequeue();
        printf("%d ", current + 1);

        // Visit all adjacent vertices of current
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (1 to %d): ", n);
    scanf("%d", &start);

    BFS(adj, n, start - 1);

    return 0;
}

