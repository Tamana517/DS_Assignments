// Q5(a): Write a program to implement a stack using two queues.

#include <iostream>
using namespace std;

#define MAX 10

class Queue {
private:
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return (front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[front++];
    }

    // Get front element
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Reset queue
    void reset() {
        front = 0;
        rear = -1;
    }

    // Display elements in queue order
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Stack implementation using two Queues
class Stack {
private:
    Queue q1, q2; 

public:
    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        // Step 1: Enqueue new element into q2
        q2.enqueue(x);

        // Step 2: Move all elements from q1 -> q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Step 3: Swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Pop operation: just dequeue from q1
    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return q1.dequeue();
    }

    // Peek operation: return front of q1
    int peek() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.getFront();
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return q1.isEmpty();
    }
    
    // Check if stack is full
    bool isFull() {
        return q1.isFull();
    }

    // Display stack contents (top -> bottom)
    void display() {
        q1.display();
    }
};

// Driver function with menu
int main() {
    Stack s;
    int choice, val;

    cout << "Stack Implementation using Two Queues\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                cout << val << " pushed onto stack.\n";
                break;

            case 2:
                val = s.pop();
                if (val != -1)
                    cout << val << " popped from stack.\n";
                break;

            case 3:
                val = s.peek();
                if (val != -1)
                    cout << "Top element is: " << val << endl;
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 5:
                if (s.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;

            case 6:
                s.display();
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
