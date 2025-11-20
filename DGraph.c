#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];            // Adjacency matrix
int visited[MAX];              // Visited array
int stack[MAX];                // Stack for finishing order
int top = -1;
int n;                         // Number of vertices

// Function to push onto stack
void push(int v) {
    stack[++top] = v;
}

// Function to pop from stack
int pop() {
    return stack[top--];
}

// DFS traversal to fill stack with vertices according to finishing times
void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs1(i);
        }
    }
    push(v); // Push to stack after visiting all adjacent vertices
}

// DFS on the reversed graph
void dfs2(int v, int transpose[MAX][MAX]) {
    printf("%d ", v + 1);  // +1 for user-friendly vertex numbering
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (transpose[v][i] == 1 && visited[i] == 0) {
            dfs2(i, transpose);
        }
    }
}

// Function to find SCCs
void findSCCs() {
    int transpose[MAX][MAX];

    // Step 1: Perform DFS and fill stack
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs1(i);
        }
    }

    // Step 2: Create the transpose of the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = adj[j][i];
        }
    }

    // Step 3: Perform DFS on transposed graph in order of decreasing finish time
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Strongly Connected Components are:\n");
    while (top != -1) {
        int v = pop();
        if (visited[v] == 0) {
            dfs2(v, transpose);
            printf("\n"); // New line for each SCC
        }
    }
}

int main() {
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

    // Find SCCs
    findSCCs();

    return 0;
}

