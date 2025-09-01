/*
Q1: Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/

#include <iostream>
#define MAX 5   // size of queue
using namespace std;

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() { // Constructor
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;  // first element being inserted
        }
        arr[++rear] = x;
        cout << x << " inserted into queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete." << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;

        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue Q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            Q.enqueue(value);
            break;
        case 2:
            Q.dequeue();
            break;
        case 3:
            Q.peek();
            break;
        case 4:
            Q.display();
            break;
        case 5:
            if (Q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is NOT Empty." << endl;
            break;
        case 6:
            if (Q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is NOT Full." << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
