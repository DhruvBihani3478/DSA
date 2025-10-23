// #include <iostream>
// using namespace std;

// class CNode {
// public:
//     int val;
//     CNode* next;
//     CNode(int v){
//         val = v;
//         next = NULL;
//     }
// };

// class CircularLinkedList {
// public:
//     CNode* head;
//     CircularLinkedList(){
//         head = NULL;
//     }

//     void insertAtEnd(int v){
//         CNode* n = new CNode(v);
//         if(!head){
//             head = n;
//             n->next = head;
//             return;
//         }
//         CNode* temp = head;
//         while(temp->next != head) temp = temp->next;
//         temp->next = n;
//         n->next = head;
//     }

//     int size(){
//         if(!head) return 0;
//         int count = 1;
//         CNode* temp = head->next;
//         while(temp != head){
//             count++;
//             temp = temp->next;
//         }
//         return count;
//     }

//     void display(){
//         if(!head){
//             cout << "List is empty\n";
//             return;
//         }
//         CNode* temp = head;
//         do{
//             cout << temp->val << " ";
//             temp = temp->next;
//         } while(temp != head);
//         cout << endl;
//     }
// };

// int main(){
//     CircularLinkedList cll;
//     cll.insertAtEnd(1);
//     cll.insertAtEnd(2);
//     cll.insertAtEnd(3);
//     cll.insertAtEnd(4);

//     cout << "Circular List: ";
//     cll.display();
//     cout << "Size of Circular Linked List: " << cll.size() << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

class DNode {
public:
    int val;
    DNode* next;
    DNode* prev;
    DNode(int v){
        val = v;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList(){
        head = NULL;
    }

    void insertAtEnd(int v){
        DNode* n = new DNode(v);
        if(!head){
            head = n;
            return;
        }
        DNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size(){
        int count = 0;
        DNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display(){
        DNode* temp = head;
        while(temp){
            cout << temp->val;
            if(temp->next) cout << "<->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Doubly Linked List: ";
    dll.display();
    cout << "Size of Doubly Linked List: " << dll.size() << endl;

    return 0;
}
