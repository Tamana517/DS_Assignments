/*
Q2: Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining
nodes after multiples of k should be left as it is.
*/

// Time Complexity: O(n), Space Comlexity: O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

// Reverse nodes in groups of k
Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    // Dummy node
    Node dummy(0);
    dummy.next = head;
    Node* prevGroup = &dummy;
    Node* curr = head;

    // Count total nodes
    int n = 0;
    while (curr) {
        n++;
        curr = curr->next;
    }

    curr = head;

    while (n >= k) {
        Node* groupPrev = prevGroup;
        Node* groupEnd = curr;
        Node* nextNode = nullptr;
        Node* prev = nullptr;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect previous group to reversed group
        groupPrev->next = prev;
        groupEnd->next = curr;

        // Move prevGroup pointer
        prevGroup = groupEnd;

        n -= k;
    }

    return dummy.next;
}

// Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
  
    int k = 3;
    head = reverseKGroup(head, k);
    printList(head); // Output: 3 2 1 6 5 4 7 8

    return 0;
}
