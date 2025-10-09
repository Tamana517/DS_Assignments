/*
Q4: Given a linked list, and an integer k, rotate the list to the left by k positions
and return the updated head.
*/

// Time Complexity: O(n), Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Count nodes
    Node* temp = head;
    int n = 1;
    while (temp->next) {
        temp = temp->next;
        n++;
    }
    
    k = k % n;
    if (k == 0) return head;

    // Find new tail (k-th node)
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    // Find old tail (already temp points to it)
    temp->next = head;   // Connect old tail to old head
    newTail->next = nullptr; // Break at new tail

    return newHead;
}

// Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example Usage
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 4;
    head = rotateLeft(head, k);
    printList(head); // Output: 50 10 20 30 40
}
