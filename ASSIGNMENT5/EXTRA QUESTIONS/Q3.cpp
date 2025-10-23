#include <iostream>
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

    void createLoop(int pos){
        if(pos <= 0) return;
        Node* temp = head;
        Node* loopNode = NULL;
        int count = 1;
        while(temp->next != NULL){
            if(count == pos) loopNode = temp;
            temp = temp->next;
            count++;
        }
        if(loopNode) temp->next = loopNode; 
    }

    void removeLoop(){
        if(head == NULL || head->next == NULL) return;
        Node* slow = head;
        Node* fast = head;

        bool loopExists = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                loopExists = true;
                break;
            }
        }

        if(!loopExists) return;

        slow = head;
        if(slow == fast){
            while(fast->next != slow) fast = fast->next;
        } else {
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL; 
    }
};

int main(){
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    cout << "Original List: ";
    l.display();
    l.createLoop(3); 
    l.removeLoop(); 
    cout << "List after removing loop: ";
    l.display();

    return 0;
}
