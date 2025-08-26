/*
Q2: Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.” 
*/

#include <stdio.h>
#include <string.h>
#define MAX 100  // max string length

// stack struct for characters
typedef struct {
    char items[MAX];  // stack elements
    int top;          // index of top
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
Stack push(Stack s, char ch) {
    if (isFull(s))
        printf("Stack Overflow!\n");
    else
        s.items[++s.top] = ch;
    return s;
}

// pop character
Stack pop(Stack s, char *ch) {
    if (isEmpty(s))
        printf("Stack Underflow!\n");
    else {
        *ch = s.items[s.top];
        s.top--;
    }
    return s;
}

// reverse string using stack
void reverseString(char str[]) {
    Stack s = init();
    int len = strlen(str);
    char ch;

    // push all characters
    for (int i = 0; i < len; i++)
        s = push(s, str[i]);

    // pop characters back into string
    for (int i = 0; i < len; i++) {
        s = pop(s, &ch);
        str[i] = ch;
    }
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
