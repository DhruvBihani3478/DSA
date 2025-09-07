#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX]; 
int top = -1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int main(){
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s",exp);

    for(int i=0; exp[i]; i++){
        char c = exp[i];
        if(isdigit(c)){
            push(c-'0');  // char → int
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
    printf("Result = %d\n", pop());
    return 0;
}
