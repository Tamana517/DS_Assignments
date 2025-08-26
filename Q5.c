// Q5: Write a program for the evaluation of a Postfix expression.

#include <stdio.h>
#include <ctype.h>  // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

// Push value onto stack
void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

// Pop value from stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1; // empty stack case
}

// Evaluate a postfix expression
int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // If operand (digit), push on stack
        if (isdigit(c)) {
            push(c - '0'); // convert char to int
        }
        // If operator, pop two operands and apply
        else {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    // Final result remains on stack
    return pop();
}

int main() {
    char exp[MAX];

    // Input expression
    printf("Enter postfix expression (e.g., 23*54*+9-): ");
    scanf("%s", exp);

    // Evaluate and display result
    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
