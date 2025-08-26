// Q5: Write a program for the evaluation of a Postfix expression.

// Q5: Program to evaluate a Postfix expression (supports multi-digit operands)

#include <stdio.h>
#include <stdlib.h>   // for atoi()
#include <string.h>   // for strtok()
#include <ctype.h>    // for isdigit()
#include <math.h>     // for pow()
#define MAX 100

// Define stack
typedef struct {
    int arr[MAX];
    int top;
} stack;

// Initialize stack
stack init() {
    stack S;
    S.top = -1;
    return S;
}
// Check empty
int isEmpty(stack S) {
    return (S.top == -1);
}

// Check full
int isFull(stack S) {
    return (S.top == MAX - 1);
}

// Push
stack push(stack S, int x) {
    if (isFull(S))
        printf("Stack Overflow!\n");
    else
        S.arr[++S.top] = x;
    return S;
}

// Pop
stack pop(stack S, int *x) {
    if (isEmpty(S))
        printf("Stack Underflow!\n");
    else
        *x = S.arr[S.top--];
    return S;
}

// Evaluate Postfix expression
int evaluatePostfix(char exp[]) {
    stack S = init();
    int op1, op2, result;
    char *token = strtok(exp, " ");  // split by spaces

    while (token != NULL) {
        if (isdigit(token[0])) {  
            // if number, convert string → int
            int num = atoi(token);
            S = push(S, num);
        }
        else {  
            // operator → pop two operands
            S = pop(S, &op2);
            S = pop(S, &op1);

            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:  result = 0;
            }
            S = push(S, result);
        }
        token = strtok(NULL, " ");  // next token
    }

    S = pop(S, &result);  // final result
    return result;
}

// Main
int main() {
    char exp[MAX];

    printf("----- Postfix Evaluation -----\n");
    printf("Enter postfix expression (use spaces, e.g. \"12 3 + 4 *\"):\n");
    fgets(exp, MAX, stdin);  // read full line

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);
    return 0;
}
