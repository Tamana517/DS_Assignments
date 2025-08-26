// Q4: Write a program to convert an Infix expression into a Postfix expression.

#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Push an element onto stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop element from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;  // stack empty
}

// Peek at top of stack
char peek() {
    if (top >= 0)
        return stack[top];
    return -1;
}

// Precedence order of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Convert Infix to Postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand (A-Z or 0-9), add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push onto stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator: check precedence before pushing
        else {
            while (top != -1 && precedence(c) <= precedence(peek())) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // Null terminate
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    // Input expression from user
    printf("Enter an infix expression (e.g., A+B*C): ");
    scanf("%s", infix);

    // Function call
    infixToPostfix(infix);

    return 0;
}
