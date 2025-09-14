#include <iostream>
#include <string>
using namespace std;
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if(top != MAX-1) stack[++top] = c;
}
char pop() {
    if(top == -1) return '\0';
    else return stack[top--];
}
int isMatchingPair(char open, char close) {
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}
int isBalanced(const string &expr) {
    top = -1;
    for(char c : expr){
        if(c=='(' || c=='{' || c=='[') push(c);
        else if(c==')' || c=='}' || c==']'){
            if(!isMatchingPair(pop(), c)) return 0;
        }
    }
    return top == -1;
}

int main() {
    string expr;
    cout<<"Enter an expression: ";
    cin>>expr;
    if(isBalanced(expr)) cout<<"Balanced expression\n";
    else cout<<"Not Balanced\n";
}
