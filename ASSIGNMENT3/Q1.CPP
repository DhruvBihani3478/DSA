#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
}
void push(int value) {
    if (isFull()) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}
void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Cannot pop\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}
void display() {
    if (isEmpty()) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
void peek() {
    if (isEmpty()) {
        printf("\nStack is empty\n");
    } else {
        printf("\nTop element: %d\n", stack[top]);
    }
}
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Display\n");
        printf("6. Peek\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isEmpty())
                    printf("\nStack is empty\n");
                else
                    printf("\nStack is not empty\n");
                break;

            case 4:
                if (isFull())
                    printf("\nStack is full\n");
                else
                    printf("\nStack is not full\n");
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
