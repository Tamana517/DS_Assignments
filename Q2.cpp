/*
Q2: Develop a menu driven program demonstrating the following operations on Circular
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/

#include <iostream>
using namespace std;

#define SIZE 5  // Size of circular queue

class CircularQueue {
private:
    int queue[SIZE];  
    int front;        
    int rear;       

public:
    CircularQueue() { // Constructor
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front); // Circular condition
    }

    // Insert an element at the rear
    void enqueue(int value) {
        if (isFull()) { 
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) { // First element
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE; // Circular increment
        }
        queue[rear] = value;
        cout << value << " enqueued successfully!" << endl;
    }

    // Remove an element from the front
    void dequeue() {
        if (isEmpty()) { 
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        int removed = queue[front];
        if (front == rear) { // Queue had only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE; // Circular increment
        }
        cout << removed << " dequeued successfully!" << endl;
    }

    // Display all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }

    // Show the front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---" << endl;
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
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                if (cq.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 6:
                if (cq.isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
