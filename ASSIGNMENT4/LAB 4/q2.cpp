#include <iostream>
#include <cstdlib>
#define MAX 5

using namespace std;

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int);
void dequeue();
bool isEmpty();
bool isFull();
void display();
void peek();

int main() {
    int choice, value;
    bool running = true;

    while (running) {
        cout << "\nCircular Queue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
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
                cout << (isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 6:
                cout << (isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 7:
                cout << "Exiting\n";
                running = false;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << ".\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    cout << value << " inserted into the queue.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << queue[front] << " removed from the queue.\n";

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return (front == (rear + 1) % MAX);
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}
