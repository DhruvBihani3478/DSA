#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
