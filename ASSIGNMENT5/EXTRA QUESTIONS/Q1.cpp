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
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getIntersection(Node* head1, Node* head2) {
        Node* a = head1;
        Node* b = head2;
        while (a != b) {
            a = (a == NULL) ? head2 : a->next;
            b = (b == NULL) ? head1 : b->next;
        }
        return a;
    }
};

int main() {
    LinkedList l1, l2;

    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.head->next->next = common; 

    l2.insertAtEnd(15);
    l2.head->next = common; 

    cout << "List 1: ";
    l1.display();
    cout << "List 2: ";
    l2.display();

    Node* inter = l1.getIntersection(l1.head, l2.head);
    if (inter) cout << "Intersection Node: " << inter->val << endl;
    else cout << "No intersection" << endl;

    return 0;
}
