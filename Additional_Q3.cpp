/*
Q3: Given a Doubly linked list containing n nodes. The task is to reverse every group of k
nodes in the list. If the number of nodes is not a multiple of k then left-out nodes, in the
end should be considered as a group and must be reversed.
Example 1:
Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 2
Output: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5 <-> NULL.
Example 2:
Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 4
Output: 4 <-> 3 <-> 2 <-> 1 <-> 6 -> 5 <-> NULL. 
*/

// Time Complexity: O(), Space Complexity: O()

#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse a group of k nodes
Node* reverseKGroup(Node* head, int k) {
    if (!head) return nullptr;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;

    while (curr) {
        Node* groupStart = curr;
        Node* groupEnd = curr;

        // Find the end of the current group
        int count = 1;
        while (count < k && groupEnd->next) {
            groupEnd = groupEnd->next;
            count++;
        }

        Node* nextGroup = groupEnd->next;

        // Reverse this group
        Node* prev = nullptr;
        Node* temp = groupStart;
        while (temp != nextGroup) {
            Node* nxt = temp->next;
            temp->next = prev;
            temp->prev = nxt;  // Update prev pointer
            prev = temp;
            temp = nxt;
        }

        // Connect previous group with current reversed group
        if (!newHead)
            newHead = groupEnd; // new head is the end of first group
        if (groupPrev)
            groupPrev->next = groupEnd;
        groupStart->next = nextGroup;
        if (nextGroup)
            nextGroup->prev = groupStart;

        groupPrev = groupStart;
        curr = nextGroup;
    }

    return newHead;
}

// Helper function to print DLL
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
        curr = curr->next;
    }
    cout << " <-> NULL\n";
}

// Helper function to insert at end
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main() {
    Node* head = nullptr;

    // Example 2
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    for (int i = 0; i < n; i++)
        head = insertEnd(head, arr[i]);

    cout << "Original List:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
