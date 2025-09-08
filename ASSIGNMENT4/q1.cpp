#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int);
void dequeue();
int isEmpty();
int isFull();
void display();
void peek();

int main() {
    int choice, value;
    while (1) {
        printf(" Queue Menu\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Peek \n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty.\n");
                break;
                
            case 6:
                if (isFull())
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 7:
                printf("Exiting\n");
                exit(0); 
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow!Cannot insert %d.\n", value);
        return;
    }
    if (front == -1) 
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d removed from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

