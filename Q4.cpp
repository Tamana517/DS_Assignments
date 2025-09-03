/*
Q4: Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b
*/

#include <iostream>
using namespace std;

#define MAX 1000  // Max size of queue

class Queue {
private:
    char arr[MAX];
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

    void enqueue(char x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = x;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return '\0';
        }
        return arr[front++];
    }

    // Get front element
    char peek() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

// Function to find first non-repeating character at each step
void firstNonRepeating(string str) {
    int freq[256] = {0};  // Frequency array for ASCII chars
    Queue q;             

    for (char ch : str) {
        // Increase frequency of the character
        freq[(int)ch]++;

        // Push current character into queue
        q.enqueue(ch);

        // Remove repeating characters from queue front
        while (!q.isEmpty() && freq[(int)q.peek()] > 1) {
            q.dequeue();
        }

        // Print result
        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.peek() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter characters (without spaces): ";
    cin >> input;

    cout << "First non-repeating characters at each step: ";
    firstNonRepeating(input);

    return 0;
}
