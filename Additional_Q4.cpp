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
#include <stack>
using namespace std;

int countStudentsUnableToEat(queue<int>& students, stack<int>& sandwiches) {
    // Count how many students prefer each type
    int count[2] = {0}; 
    queue<int> tempQueue = students;

    // Count students' preferences
    while (!tempQueue.empty()) {
        count[tempQueue.front()]++;
        tempQueue.pop();
    }

    // Process the sandwiches
    while (!sandwiches.empty()) {
        int topSandwich = sandwiches.top();

        // If no student prefers this sandwich, stop early
        if (count[topSandwich] == 0) {
            break;
        }

        // Otherwise, serve the sandwich to the first student who prefers it
        while (!students.empty()) {
            int student = students.front();
            students.pop();

            if (student == topSandwich) {
                // Student takes the sandwich
                count[topSandwich]--;
                sandwiches.pop();
                break; // Move to next sandwich
            } else {
                // Student goes to the end of the queue
                students.push(student);
            }
        }
    }

    // Remaining students who couldn't eat are the size of the queue
    return students.size();
}

int main() {
    // Input: students' preferences and sandwiches stack
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    queue<int> students;
    stack<int> sandwiches;

    cout << "Enter students' preferences (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; i++) {
        int pref;
        cin >> pref;
        students.push(pref);
    }

    cout << "Enter sandwiches stack (top to bottom, 0 for circular, 1 for square):\n";
    // Read input in reverse order for stack (since top is entered first)
    int temp[n];
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        sandwiches.push(temp[i]);
    }

    int result = countStudentsUnableToEat(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
