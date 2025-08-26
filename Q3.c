// Q3: Check if an expression has balanced parentheses
#include <stdio.h>
#include <string.h>
#define MAX 100  // max expression length

// stack struct for characters
typedef struct {
    char items[MAX]; // stack elements
    int top;         // index of top
} Stack;

// initialize stack
Stack init() {
    Stack s;
    s.top = -1;
    return s;
}

// check empty
int isEmpty(Stack s) {
    return s.top == -1;
}

// check full
int isFull(Stack s) {
    return s.top == MAX - 1;
}

// push character
Stack push(Stack s, char c) {
    if (isFull(s))
        printf("Stack Overflow!\n");
    else
        s.items[++s.top] = c;
    return s;
}

// pop character
Stack pop(Stack s, char *ch) {
    if (isEmpty(s))
        *ch = '\0';
    else {
        *ch = s.items[s.top];
        s.top--;
    }
    return s;
}

// check if opening & closing brackets match
int match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// check balance of expression
int isBalanced(char exp[]) {
    Stack s = init();
    char ch;

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s = push(s, exp[i]);          // push opening bracket
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            s = pop(s, &ch);              // pop last opening
            if (!match(ch, exp[i]))
                return 0; // mismatch
        }
    }
    return isEmpty(s); // balanced if stack empty
}

// main
int main() {
    char exp[MAX];
    
    printf("Enter expression: ");
    scanf(" %[^\n]", exp); // read line with spaces

    if (isBalanced(exp))
        printf("Expression is Balanced\n");
    else
        printf("Expression is Not Balanced\n");

    return 0;
}
