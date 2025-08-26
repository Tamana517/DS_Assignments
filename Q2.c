/*
Q2: Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.” 
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push to stack
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack Overflow\n");
}

// Pop from stack
char pop() {
    if (top >= 0)
        return stack[top--];
    else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int main() {
    char str[MAX];
    int i, len;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);   // input with spaces

    len = strlen(str);

    // Push all characters
    for (i = 0; i < len; i++)
        push(str[i]);

    // Pop and print reversed
    printf("Reversed: ");
    for (i = 0; i < len; i++)
        printf("%c", pop());
    printf("\n");

    return 0;
}
