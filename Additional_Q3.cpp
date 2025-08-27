/*
Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
array in order of their appearance in the array. Note: The Next Greater Element for an element x is
the first greater element on the right side of x in the array. Elements for which no greater element
exist, consider the next greater element as -1.
 */

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <stack>
using namespace std;

void nearestSmallerToLeft(int arr[], int n) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        // remove larger/equal elements
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // print result
        if (s.empty())
            cout << -1 << " ";
        else
            cout << s.top() << " ";

        // push current element
        s.push(arr[i]);
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Nearest Smaller Elements:\n";
    nearestSmallerToLeft(arr, n);

    return 0;
}
