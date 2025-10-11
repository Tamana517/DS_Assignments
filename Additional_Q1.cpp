/*
Q1: Given a Circular linked list. The task is split into two Circular Linked lists. If there are an
odd number of nodes in the given circular linked list then out of the resulting two halved
lists, the first list should have one node more than the second list. 
Input: 10->4->9
Output: 10->4 , 9
*/

// Time Complexity: O(n), Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to split a circular linked list into two halves
void splitCircularList(Node* head, Node** head1, Node** head2) {
    if (!head) return;

    Node *slow = head, *fast = head;

    // Using slow-fast pointer technique
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Set heads of the two halves
    *head1 = head;
    *head2 = slow->next;

    // Make first half circular
    slow->next = *head1;

    // Make second half circular
    if (fast->next == head) // Even nodes
        fast->next = *head2;
    else // Odd nodes
        fast->next->next = *head2;
}

// Driver code
int main() {
    Node* head = createNode(10);
    head->next = createNode(4);
    head->next->next = createNode(9);
    head->next->next->next = head; // Make it circular

    Node *head1 = nullptr, *head2 = nullptr;
    splitCircularList(head, &head1, &head2);

    cout << "First half: ";
    printList(head1);
    cout << "Second half: ";
    printList(head2);

    return 0;
}
