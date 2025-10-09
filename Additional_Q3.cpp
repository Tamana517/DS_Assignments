// Q3: Given a linked list, remove the loop if it exists.

Time Complexity: O(n), Space complexity: O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

// Detect and remove loop
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // loop detected
    }

    // If no loop
    if (slow != fast) return;

    // Step 2: Find start of the loop
    slow = head;
    if (slow == fast) {
        // Loop starts at head
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Break the loop
    fast->next = nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(3);
    head->next->next->next = new Node(6);

    // Create a loop for testing (6 -> 7)
    head->next->next->next->next = head->next;

    removeLoop(head);  // Removes loop if present

    cout << "Linked List after removing loop:\n";
    printList(head);

    return 0;
}
