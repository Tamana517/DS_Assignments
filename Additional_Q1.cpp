/*
Given an array A, find the nearest smaller element for every element A[i] in the array such that the
element has an index smaller than i.
*/

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <stack>
using namespace std;

void nearestSmallerToLeft(int arr[], int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= arr[i]) // pop bigger elements
            s.pop();

        if (s.empty()) cout << -1 << " ";          // no smaller element
        else cout << s.top() << " ";              // nearest smaller element

        s.push(arr[i]); // push current element
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n]; // input array
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Nearest smaller elements:\n";
    nearestSmallerToLeft(arr, n);

    return 0;
}
