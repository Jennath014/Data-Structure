#include <stdio.h>

#define MAX 10  // Maximum number of elements

int parent[MAX];  // Array to store parent of each element

// Function to create disjoint sets
void create(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;  // Each element is its own parent initially
    }
    printf("Disjoint sets created with %d elements.\n", n);
}

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // Path compression
    return parent[x];
}

// Union function
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX;  // Merge the two sets
        printf("Union of %d and %d completed.\n", x, y);
    } else {
        printf("%d and %d are already in the same set.\n", x, y);
    }
}

// Function to display parent array
void display(int n) {
    printf("Element: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\nParent:  ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", parent[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, choice, x, y;

    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of elements!\n");
        return 0;
    }

    create(n);

    while (1) {
        printf("\n--- Disjoint Set Menu ---\n");
        printf("1. Union of two elements\n");
        printf("2. Find the representative of an element\n");
        printf("3. Display parent array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);
                if (x >= 1 && x <= n && y >= 1 && y <= n)
                    unionSets(x, y);
                else
                    printf("Invalid elements!\n");
                break;

            case 2:
                printf("Enter element to find: ");
                scanf("%d", &x);
                if (x >= 1 && x <= n)
                    printf("Representative of %d is %d\n", x, find(x));
                else
                    printf("Invalid element!\n");
                break;

            case 3:
                display(n);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

