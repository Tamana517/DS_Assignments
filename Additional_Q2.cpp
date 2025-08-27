#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> s; // Main stack (stores encoded values when needed)
    long long minElement; // Stores current minimum

public:
    MinStack() {}

    void push(int x) {
        if (s.empty()) {
            s.push(x);         // First element, push normally
            minElement = x;    // Initialize min
        } else {
            if (x < minElement) {
                s.push(2LL * x - minElement); // Encode new min
                minElement = x;               // Update min
            } else {
                s.push(x);    // Push normally
            }
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        long long topVal = s.top();
        s.pop();
        if (topVal < minElement) {
            minElement = 2LL * minElement - topVal; // Decode previous min
        }
    }

    int top() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        long long topVal = s.top();
        if (topVal < minElement)
            return minElement; // Top is encoded, return min
        else
            return topVal;     // Normal value
    }

    int getMin() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minElement; // Current minimum
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    MinStack stack;
    int choice, value;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop(); 
                break;
            case 3:
                value = stack.top();
                if(value != -1)
                    cout << "Top: " << value << endl;
                break;
            case 4:
                value = stack.getMin(); // Show current min
                if(value != -1)
                    cout << "Minimum: " << value << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 5);

    return 0;
}
