#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;
int count = 0; 
void enqueue(int value) 
	{
    	if ((front == (rear + 1) % MAX)) 
    		{
        	printf("Queue Overflow! Cannot insert %d.\n", value);
        	return;
    		}
	if (front == -1) 
		{ 
        	front = 0;
        	rear = 0;
    		} 
    	else 
    		{
        	rear = (rear + 1) % MAX;
    		}
    	queue[rear] = value;
    	count++;
    	printf("%d inserted into the queue.\n", value);
	}		
void dequeue()
	{
	if (front == -1) 
		{
        	printf("Queue Underflow! Nothing to delete.\n");
        	return;
    		}
    	int deletedValue = queue[front];
    	if (front == rear) 
    		{ 
        	front = -1;
        	rear = -1;
    		}
    	else 
    		{
        	front = (front + 1) % MAX;
    		}
    	count--;
    	printf("Deleted element: %d\n", deletedValue);
	}
void display() 
	{
    	if (front == -1) 
    		{
        	printf("Queue is empty!\n");
        	return;
    		}
    	printf("Queue elements: ");
    	int i = front;
    	while (i != rear) 
    		{
        	printf("%d ", queue[i]);
        	i = (i + 1) % MAX;
    		}
    	printf("%d\n", queue[rear]);
    	}
void countElements() 
	{
    	printf("Total number of elements in the queue: %d\n", count);
	}
int main() 
	{
    	int choice, value;
	printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
    	while (1) 
    		{
        		
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch (choice) 
        		{
            		case 1:
                	printf("Enter value to insert: ");
                	scanf("%d", &value);
                	enqueue(value);
                	break;

            		case 2:
                	dequeue();
                	break;

            		case 3:
                	display();
                	break;

            		case 4:
                	countElements();
                	break;

            		case 5:
                	printf("Exiting program...\n");
                	exit(0);

            		default:
                	printf("Invalid choice! Please try again.\n");
        		}
    		}

    	return 0;
	}
