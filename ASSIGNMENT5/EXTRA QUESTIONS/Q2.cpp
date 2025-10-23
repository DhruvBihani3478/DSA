#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insertAtEnd(int v){
        Node* n = new Node(v);
        if(head == NULL){
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = n;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val;
            if(temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverseK(Node* head, int k){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;
        Node* temp = head;
        int i;
        for(int i = 0; i < k && temp; i++) temp = temp->next;
        if(i < k) return head;
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next != NULL) head->next = reverseK(next, k);
        return prev;
    }

    void reverseInGroups(int k){
        head = reverseK(head, k);
    }
};

int main(){
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertAtEnd(7);

    cout << "Original List: ";
    l.display();

    int k = 3;
    l.reverseInGroups(k);

    cout << "Reversed in Groups of " << k << ": ";
    l.display();

    return 0;
}
