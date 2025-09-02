/*
Q3: Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/

#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of queue

class Queue {
private:
    int arr[MAX];    
    int front, rear;

public:
    // Constructor: initializes empty queue
    Queue() {
        front = 0;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Add element at the rear (enqueue)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = x;
    }

    // Remove element from the front (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[front++];
    }

    // Display queue elements
    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Check for empty queue
    if (n == 0) {
        cout << "Queue is empty! Nothing to interleave." << endl;
        return 0;
    }

    // Check if number of elements is odd
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements. Cannot interleave." << endl;
        return 0;
    }

    Queue q; // Main queue

    // Input elements into the queue
    cout << "Enter elements of the queue: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    int half = n / 2;
    Queue q1, q2;   // Two helper queues

    // First half goes into q1
    for (int i = 0; i < half; i++)
        q1.enqueue(q.dequeue());

    // Second half goes into q2
    for (int i = half; i < n; i++)
        q2.enqueue(q.dequeue());

    // Resultant interleaved queue
    Queue result;

    // Alternate elements from q1 and q2
    while (!q1.isEmpty() && !q2.isEmpty()) {
        result.enqueue(q1.dequeue());
        result.enqueue(q2.dequeue());
    }

    // Display final interleaved queue
    cout << "Interleaved Queue: ";
    result.display();

    return 0;
}
