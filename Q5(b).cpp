// Q5(b): Write a program to implement a stack using one queue.

#include <iostream>
using namespace std;

#define MAX 10

class Queue {
private:
    int arr[MAX];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == MAX);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int data = arr[front];
        front = (front + 1) % MAX;
        count--;
        return data;
    }

    int frontElement() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int size() {
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// Stack implemented using ONE queue
class Stack {
private:
    Queue q;

public:
    void push(int x) {
        if (q.isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        q.enqueue(x);

        // Rotate queue so that new element comes to front
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.enqueue(q.dequeue());
        }
        cout << x << " pushed into stack!" << endl;
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << q.dequeue() << " popped from stack!" << endl;
    }

    void top() {
        if (q.isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << q.frontElement() << endl;
        }
    }

    bool isEmpty() {
        return q.isEmpty();
    }

    bool isFull() {
        return q.isFull();
    }

    void display() {
        q.display();
    }
};

// Driver function with menu
int main() {
    Stack st;
    int choice, value;

    do {
        cout << "\n--- Stack Using One Queue ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            st.push(value);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.top();
            break;
        case 4:
            if (st.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
        case 5:
            if (st.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;
        case 6:
            st.display();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
