/*
Q4: Given an array of integers temperatures represents the daily temperatures, return an
array answer such that answer[i] is the number of days you have to wait after the ith day to get a
warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

//Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <stack>
using namespace std;

// Function to calculate days until a warmer temperature
void dailyTemperatures(int temperatures[], int n, int answer[]) {
    stack<int> s; // stores indices

    // Initialize answer array with 0
    for (int i = 0; i < n; i++) {
        answer[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = i - idx; // number of days to wait
        }
        s.push(i); // push current day's index
    }
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[n], answer[n];

    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    dailyTemperatures(temperatures, n, answer); // call function

    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
