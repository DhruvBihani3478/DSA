#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int v) {
        Node* n = new Node(v);
        if(head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->val;
            if(temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void rotateLeft(int k) {
        if(head == NULL || head->next == NULL || k == 0) return;
        Node* temp = head;
        int len = 1;
        while(temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        k = k % len;
        if(k == 0) return;
        temp->next = head;
        Node* newEnd = head;
        for(int i = 1; i < k; i++) newEnd = newEnd->next;
        head = newEnd->next;
        newEnd->next = NULL;
    }
};

int main() {
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);

    cout << "Original List: ";
    l.display();

    int k = 2;
    l.rotateLeft(k);

    cout << "List after rotating left by " << k << " positions: ";
    l.display();

    return 0;
}
