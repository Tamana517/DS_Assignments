// Q3: Write a program that checks if an expression has balanced parentheses. 

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top;

// Push to stack
void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}

// Pop from stack
char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

// Check if pair matches
int match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Check balance
int isBalanced(char exp[]) {
    top = -1;  // reset stack before each check
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char open = pop();
            if (!match(open, exp[i]))
                return 0; // mismatch
        }
    }
    return (top == -1); // balanced if stack empty
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf(" %[^\n]", exp);  // read input with spaces

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
