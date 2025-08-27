/*
Q5: You have an array A of integers of size N, an array B (initially empty) and a stack S (initially
empty). You are allowed to do the following operations:
a) Take the first element of array A and push it into S and remove it from A.
b) Take the top element from stack S, append it to the end of array B and remove it from S.
You have to tell if it possible to move all the elements of array A to array B using the above
operations such that finally the array B is sorted in ascending order.
*/

// Time Complexity: O(nlog(n)), Space Complexity: O(n)

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check if array can be sorted using a stack
bool canSortWithStack(int A[], int N) {
    stack<int> S;
    int nextSmallest = 0; // pointer to the next element in sorted order

    // Create a copy of A to sort
    int Sorted[N];
    for (int i = 0; i < N; i++)
        Sorted[i] = A[i];

    // Sort the array using built-in sort()
    sort(Sorted, Sorted + N);

    // Simulate stack operations
    for (int i = 0; i < N; i++) {
        S.push(A[i]);
        while (!S.empty() && S.top() == Sorted[nextSmallest]) {
            S.pop();
            nextSmallest++;
        }
    }

    return nextSmallest == N;
}

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    int A[N];
    cout << "Enter " << N << " elements of the array:\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (canSortWithStack(A, N))
        cout << "Yes, it is possible to sort using the stack.\n";
    else
        cout << "No, it is not possible.\n";

    return 0;
}
