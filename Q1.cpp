/*
Q1: Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek(). 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // max stack size

int stack[MAX];
int top = -1;

// check empty
int isEmpty() { return top == -1; }

// check full
int isFull() { return top == MAX - 1; }

// insert
void push(int x) {
    if (isFull())
        printf("Stack Overflow!\n");
    else {
        stack[++top] = x;
        printf("%d pushed\n", x);
        display(); // show after push
    }
}

// remove
void pop() {
    if (isEmpty())
        printf("Stack Underflow!\n");
    else {
        printf("%d popped\n", stack[top--]);
        display(); // show after pop
    }
}

// show top
void peek() {
    if (isEmpty())
        printf("Stack is Empty!\n");
    else
        printf("Top element = %d\n", stack[top]);
}

// print stack
void display() {
    if (isEmpty())
        printf("Stack is Empty!\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2: pop(); break;
        case 3: printf(isEmpty() ? "Yes, Empty\n" : "Not Empty\n"); break;
        case 4: printf(isFull() ? "Yes, Full\n" : "Not Full\n"); break;
        case 5: display(); break;
        case 6: peek(); break;
        case 7: exit(0);
        default: printf("Invalid choice!\n");
        }
    }
}
