#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 5

int stack[MAX];
int top = -1;

int isFull() { return top == MAX-1; }
int isEmpty() { return top == -1; }

void push(int value) {
    if(isFull()) cout << "\nStack Overflow! Cannot push " << value << endl;
    else {
        stack[++top] = value;
        cout << value << " pushed to stack" << endl;
    }
}
void pop() {
    if(isEmpty()) cout << "\nStack Underflow! Cannot pop\n";
    else cout << stack[top--] << " popped from stack\n";
}
void display() {
    if(isEmpty()) cout << "\nStack is empty\n";
    else {
        cout << "\nStack elements (top to bottom): ";
        for(int i=top; i>=0; i--) cout << stack[i] << " ";
        cout << endl;
    }
}
void peek() {
    if(isEmpty()) cout << "\nStack is empty\n";
    else cout << "\nTop element: " << stack[top] << endl;
}

int main() {
    int choice, value;
    while(1){
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(isEmpty()) cout << "\nStack is empty\n";
                else cout << "\nStack is not empty\n";
                break;
            case 4:
                if(isFull()) cout << "\nStack is full\n";
                else cout << "\nStack is not full\n";
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "\nExiting...\n";
                exit(0);
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    }
}
