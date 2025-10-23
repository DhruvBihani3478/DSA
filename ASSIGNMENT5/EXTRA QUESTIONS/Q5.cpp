#include <iostream>
using namespace std;

class Node{
public:
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class Polynomial{
public:
    Node* head;
    Polynomial(){
        head = NULL;
    }

    void insertAtEnd(int c, int p){
        Node* n = new Node(c, p);
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
            cout << temp->coeff << "x^" << temp->pow;
            if(temp->next != NULL) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    static Polynomial add(Polynomial &p1, Polynomial &p2){
        Polynomial result;
        Node* t1 = p1.head;
        Node* t2 = p2.head;

        while(t1 != NULL && t2 != NULL){
            if(t1->pow == t2->pow){
                result.insertAtEnd(t1->coeff + t2->coeff, t1->pow);
                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1->pow > t2->pow){
                result.insertAtEnd(t1->coeff, t1->pow);
                t1 = t1->next;
            }
            else{
                result.insertAtEnd(t2->coeff, t2->pow);
                t2 = t2->next;
            }
        }

        while(t1 != NULL){
            result.insertAtEnd(t1->coeff, t1->pow);
            t1 = t1->next;
        }

        while(t2 != NULL){
            result.insertAtEnd(t2->coeff, t2->pow);
            t2 = t2->next;
        }

        return result;
    }
};

int main(){
    Polynomial p1, p2;
    p1.insertAtEnd(5, 3);
    p1.insertAtEnd(4, 2);
    p1.insertAtEnd(2, 0);
    p2.insertAtEnd(3, 3);
    p2.insertAtEnd(1, 1);
    p2.insertAtEnd(6, 0);

    cout << "Polynomial 1: ";
    p1.display();
    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = Polynomial::add(p1, p2);
    cout << "Sum: ";
    sum.display();

    return 0;
}
