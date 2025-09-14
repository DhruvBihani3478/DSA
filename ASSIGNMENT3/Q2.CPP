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

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int n = str.length();

    for(int i = 0; i < n; i++) push(str[i]);
    for(int i = 0; i < n; i++) str[i] = pop();

    cout << "Reversed string: " << str << endl;
}
