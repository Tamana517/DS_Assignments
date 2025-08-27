/*
Q1: Given an array A, find the nearest smaller element for every element A[i] in the array such that the
element has an index smaller than i.
*/

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <stack>
using namespace std;

void nearestSmallerToLeft(int arr[], int n) {
    stack<int> s;           
    int result[n];          

    for (int i = 0; i < n; i++) {
        // Remove all elements >= current
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack empty -> no smaller element
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        // Push current element
        s.push(arr[i]);
    }

    // Print results
    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    nearestSmallerToLeft(arr, n);

    return 0;
}
