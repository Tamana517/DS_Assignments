/*
Q1: Given a function n, write a function that generates and prints all binary numbers with decimal
values from 1 to n.
Input: n = 2
Output: 1, 10
*/

#include <iostream>
#include <queue>
using namespace std;

// Function to generate and print binary numbers from 1 to n
void generateBinaryNumbers(int n) {
    queue<string> q;  // Queue to hold binary strings
    q.push("1");      // Start with "1"

    for (int i = 1; i <= n; i++) {
        string s = q.front(); // Get the front element
        q.pop();              // Remove it from the queue

        cout << s << endl;   // Print the current binary number

        // Generate next binary numbers by appending "0" and "1"
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << " are:" << endl;
    generateBinaryNumbers(n);

    return 0;
}
