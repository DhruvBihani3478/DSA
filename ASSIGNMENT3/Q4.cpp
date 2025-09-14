#include <iostream>
#include <cctype>
#include <string>
using namespace std;
#define MAX 100

char s[MAX]; 
int top = -1;

void push(char c){ s[++top] = c; }
char pop(){ return s[top--]; }
char peek(){ return s[top]; }

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int main(){
    string infix, post;
    cout << "Enter infix: ";
    cin >> infix;
    int k = 0;

    for(char c : infix){
        if(isalnum(c)) post += c;
        else if(c=='(') push(c);
        else if(c==')'){
            while(top != -1 && peek() != '(') post += pop();
            pop();
        } else {
            while(top != -1 && prec(peek()) >= prec(c)) post += pop();
            push(c);
        }
    }
    while(top != -1) post += pop();

    cout << "Postfix: " << post << endl;
}
