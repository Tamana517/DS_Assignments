/*
Q5: Write a program to check if a linked list is Circular Linked List or not.
Input: 2 -> 4 -> 6 -> 7 -> 5  
(Note: last node points to head)
Output: True
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to check if linked list is a Circular Linked List
bool isCLL(Node* head) {
    if (!head) return true; // Empty list considered circular

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect a cycle in the linked list using two pointers moving at different speeds
    do {
        if (!fast || !fast->next) return false; // no cycle
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Step 2: Check if cycle starts at head
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return (slow == head); // true if cycle starts at head
}

// Driver code
int main() {
    // Circular Linked List
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head; // last node points to head

    cout << (isCLL(head) ? "Linked list is a Circular Linked List\n" : "Linked list is not a Circular Linked List\n");

    return 0;
}
