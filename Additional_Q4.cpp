/*
Q4: The school cafeteria offers circular and square sandwiches at lunch break, referred to by
numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
sandwiches are placed in a stack. At each step:
● If the student at the front of the queue prefers the sandwich on the top of the stack, they
will take it and leave the queue.
● Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus
unable to eat
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0
*/

// Time Complexity: O(n)

#include <iostream>
#include <queue>
using namespace std;

int countStudentsUnableToEat(queue<int> students, queue<int> sandwiches) {
    int count[2] = {0}; // count[0] for circular (0), count[1] for square (1)

    // Count students' preferences
    while (!students.empty()) {
        count[students.front()]++;
        students.pop();
    }

    // Serve sandwiches
    while (!sandwiches.empty()) {
        int top = sandwiches.front();
        if (count[top] > 0) {
            // Serve the sandwich and reduce count
            count[top]--;
            sandwiches.pop();
        } else {
            // No student left who prefers this sandwich
            break;
        }
    }

    // Remaining students are unable to eat
    return count[0] + count[1];
}

int main() {
    int n;
    cout << "Enter the number of students/sandwiches: ";
    cin >> n;

    queue<int> students;
    queue<int> sandwiches;

    cout << "Enter the students' preferences (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        students.push(s);
    }

    cout << "Enter the sandwiches' types in stack order (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        sandwiches.push(s);
    }

    int result = countStudentsUnableToEat(students, sandwiches);

    cout << "Output: " << result << endl;

    return 0;
}
