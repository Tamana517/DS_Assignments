// Q4: Convert Infix expression to Postfix expression

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100  // max expression length

// stack struct for characters (operators)
typedef struct {
    char items[MAX]; // operator stack
    int top;
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
    if (!isFull(s))
        s.items[++s.top] = c;
    return s;
}

// pop character
Stack pop(Stack s, char *ch) {
    if (!isEmpty(s)) {
        *ch = s.items[s.top];
        s.top--;
    } else
        *ch = '\0';
    return s;
}

// view top element
char peek(Stack s) {
    if (!isEmpty(s))
        return s.items[s.top];
    return '\0';
}

// precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s = init();
    int i, k = 0;
    char ch, temp;

    for (i = 0; infix[i]; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            // operand goes directly to postfix
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            s = push(s, ch);
        }
        else if (ch == ')') {
            // pop until '(' is found
            while (!isEmpty(s) && peek(s) != '(') {
                s = pop(s, &temp);
                postfix[k++] = temp;
            }
            s = pop(s, &temp); // discard '('
        }
        else if (isOperator(ch)) {
            // pop operators with >= precedence
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch)) {
                s = pop(s, &temp);
                postfix[k++] = temp;
            }
            s = push(s, ch);
        }
    }

    // pop remaining operators
    while (!isEmpty(s)) {
        s = pop(s, &temp);
        postfix[k++] = temp;
    }

    postfix[k] = '\0'; // terminate string
}

// main
int main() {
    char infix[MAX], postfix[MAX];

    printf("\n--------- INFIX TO POSTFIX CONVERSION ---------\n");
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("------------------------------------------------\n");

    return 0;
}
