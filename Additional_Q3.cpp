/*
Q3: Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
array in order of their appearance in the array. Note: The Next Greater Element for an element x is
the first greater element on the right side of x in the array. Elements for which no greater element
exist, consider the next greater element as -1.
 */

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n) {
    stack<int> s;           
    int result[n];          

    for (int i = n - 1; i >= 0; i--) {
        // Remove all elements <= current
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack empty -> no greater element
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        // Push current element
        s.push(arr[i]);
    }

    // Print results
    cout << "Next greater elements: ";
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

    nextGreaterElement(arr, n);

    return 0;
}
