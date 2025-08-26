/*
Q1: Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek(). 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // max stack size

typedef struct {
    int items[MAX]; // stack elements
    int top;        // index of top
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

// push element
Stack push(Stack s, int x) {
    if (isFull(s))
        printf("Stack Overflow!\n");
    else
        s.items[++s.top] = x;
    return s;
}

// pop element
Stack pop(Stack s) {
    if (isEmpty(s))
        printf("Stack Underflow!\n");
    else
        --s.top;
    return s;
}

// view top element
int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return s.items[s.top];
}

// display stack
void display(Stack s) {
    if (isEmpty(s))
        printf("Stack is Empty!\n");
    else {
        printf("Stack: ");
        for (int i = s.top; i >= 0; i--)
            printf("%d ", s.items[i]);
        printf("\n");
    }
}

// main menu
int main() {
    Stack s = init(); // create stack
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // push
            printf("Enter value: ");
            scanf("%d", &value);
            s = push(s, value);
            display(s);
            break;
        case 2: // pop
            s = pop(s);
            display(s);
            break;
        case 3: // check empty
            printf(isEmpty(s) ? "Yes, Empty\n" : "Not Empty\n");
            break;
        case 4: // check full
            printf(isFull(s) ? "Yes, Full\n" : "Not Full\n");
            break;
        case 5: // display stack
            display(s);
            break;
        case 6: // peek top
            printf("Top element = %d\n", peek(s));
            break;
        case 7: // exit
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
