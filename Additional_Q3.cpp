/*
Q3: Given a Queue consisting of first n natural numbers (in random order). The task is to check whether
the given Queue elements can be arranged in increasing order in another Queue using a stack. The
operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in the another Queue.
Input : Queue[] = { 5, 1, 2, 3, 4 }
Output : Yes
*/

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to check if the queue can be sorted using a stack
bool canBeSorted(queue<int> q) {
    stack<int> s;           // Temporary stack
    int expected = 1;       // Expected number to enqueue in sorted order

    while (!q.empty() || !s.empty()) {
        // If front of queue is the expected number, enqueue it in output queue
        if (!q.empty() && q.front() == expected) {
            q.pop();
            expected++;
        }
        // Else if top of stack is expected, pop it to output queue
        else if (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
        // Else move the front of queue to stack
        else if (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        // If queue is empty and top of stack is not expected, sorting not possible
        else {
            return false;
        }
    }
    return true;
}

int main() {
    queue<int> q;
    int n;

    // User input for number of elements
    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter " << n << " elements (first n natural numbers in any order): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Check if it can be sorted and print result
    if (canBeSorted(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
