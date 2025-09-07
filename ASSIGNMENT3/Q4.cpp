#include <stdio.h>
#include <ctype.h>
#define MAX 100

char s[MAX]; int top=-1;

void push(char c){ s[++top]=c; }
char pop(){ return s[top--]; }
char peek(){ return s[top]; }

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int main(){
    char infix[MAX],post[MAX]; 
    int i=0,k=0;
    printf("Enter infix: ");
    scanf("%s",infix);

    while(infix[i]){
        char c=infix[i++];
        if(isalnum(c)) post[k++]=c;
        else if(c=='(') push(c);
        else if(c==')'){
            while(top!=-1 && peek()!='(') post[k++]=pop();
            pop();
        } else {
            while(top!=-1 && prec(peek())>=prec(c)) post[k++]=pop();
            push(c);
        }
    }
    while(top!=-1) post[k++]=pop();
    post[k]='\0';

    printf("Postfix: %s\n",post);
}
