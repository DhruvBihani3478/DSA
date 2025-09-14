#include <iostream>
#include <cctype>
#include <string>
using namespace std;
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int main(){
    string exp;
    cout<<"Enter postfix expression: ";
    cin>>exp;

    for(char c : exp){
        if(isdigit(c)){
            push(c-'0');
        } else {
            int b=pop(), a=pop();
            switch(c){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
    }
    cout<<"Result = "<<pop()<<endl;
    return 0;
}
