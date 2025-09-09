/*
Q2: Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
operations allowed on queue are:
1. enqueue() : Adds an item to rear of queue.
2. dequeue() : Removes an item from front of queue.
3. isEmpty() : Checks if a queue is empty.
Input: 11, 5, 4, 21
Output: 4, 5, 11, 21
*/

#include <iostream>
#include <queue>
#include <climits> // for INT_MAX
using namespace std;

// Function to sort the queue using only allowed operations
void sortQueue(queue<int>& q) {
    int n = q.size();

    // Perform n iterations to sort the queue
    for (int i = 0; i < n; i++) {
        int minIndex = -1;
        int minValue = INT_MAX; // Initialize minValue with the largest possible int value

        int size = q.size();

        // Find the minimum element from unsorted part
        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();

            // Find the minimum value in the current queue state
            if (curr < minValue && j <= size - i - 1) {
                minValue = curr;
                minIndex = j;
            }
            q.push(curr);
        }

        // Move elements except the minimum to the rear, and enqueue minValue at the end
        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();

            if (j == minIndex) {
                // Skip the minimum element once
                continue;
            }
            q.push(curr);
        }
        q.push(minValue); // Place the minimum element at the rear after all others
    }
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    // Sort the queue
    sortQueue(q);

    // Output sorted queue
    cout << "Queue after sorting: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
