#include <stdio.h>

#define MAX 10  // Maximum size of universal set

// Function to input a set as bit string
void inputSet(int set[], int n) {
    printf("Enter elements of the set (0 or 1) for each position:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &set[i]);
        if (set[i] != 0 && set[i] != 1) {
            printf("Invalid input! Enter 0 or 1 only.\n");
            i--; // repeat input for this index
        }
    }
}

// Function to display a set as bit string
void displaySet(int set[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", set[i]);
    }
    printf("\n");
}

// Union operation
void unionSet(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] | B[i];  // OR operation
    }
}

// Intersection operation
void intersectionSet(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] & B[i];  // AND operation
    }
}

// Difference operation (A - B)
void differenceSet(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] & (!B[i]);  // A AND NOT B
    }
}

// Main Program
int main() {
    int A[MAX], B[MAX], result[MAX];
    int n, choice;

    printf("Enter size of the universal set: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid size!\n");
        return 0;
    }

    printf("\nEnter Set A:\n");
    inputSet(A, n);

    printf("\nEnter Set B:\n");
    inputSet(B, n);

    while (1) {
        printf("\n--- Set Operations Menu ---\n");
        printf("1. Display Sets\n");
        printf("2. Union (A ∪ B)\n");
        printf("3. Intersection (A ∩ B)\n");
        printf("4. Difference (A - B)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Set A: ");
                displaySet(A, n);
                printf("Set B: ");
                displaySet(B, n);
                break;

            case 2:
                unionSet(A, B, result, n);
                printf("A ∪ B = ");
                displaySet(result, n);
                break;

            case 3:
                intersectionSet(A, B, result, n);
                printf("A ∩ B = ");
                displaySet(result, n);
                break;

            case 4:
                differenceSet(A, B, result, n);
                printf("A - B = ");
                displaySet(result, n);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

