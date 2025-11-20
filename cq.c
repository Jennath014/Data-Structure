#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert element into circular queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", element);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    printf("Inserted %d\n", element);
}

// Delete element from circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int element = queue[front];
    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return element;
}

// Display elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Count number of elements in the queue
int count() {
    if (isEmpty()) {
        return 0;
    }
    if (rear >= front) {
        return rear - front + 1;
    } else {
        return SIZE - front + rear + 1;
    }
}

int main() {
    int choice, element, result;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                result = dequeue();
                if (result != -1)
                    printf("Deleted element: %d\n", result);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Number of elements in queue: %d\n", count());
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
}
