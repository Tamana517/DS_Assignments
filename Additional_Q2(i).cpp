/*
Q2(i): Given a Doubly linked list containing N nodes, the task is
to remove all the nodes from list which contains element whose parity is even. 
Note: Parity means no of 1 in binary form
11 -> 1011, parity = 3
15 -> 1111, parity = 4
Example:
Input: DLL: 18 <=> 15 <=> 8 <=> 9 <=> 14
Output: 8 <=> 14
*/

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
using namespace std;

// Node for DLL
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Count number of 1s in binary and return parity (1 = odd, 0 = even)
int countParity(int n) {
    int c = 0;
    while (n) {
        c += n & 1;
        n >>= 1;
    }
    return c % 2;
}

// Insert at end using tail pointer
void insertEnd(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Remove nodes with even parity
void removeEvenParity(Node*& head) {
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next;
        if (countParity(temp->data) == 0) { // even parity
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            delete temp;
        }
        temp = nextNode;
    }
}

// Print DLL
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <=> ";
        temp = temp->next;
    }
    cout << endl;
}

// Main
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertEnd(head, tail, 18);
    insertEnd(head, tail, 15);
    insertEnd(head, tail, 8);
    insertEnd(head, tail, 9);
    insertEnd(head, tail, 14);

    removeEvenParity(head);

    cout << "DLL after removing even parity nodes: ";
    printDLL(head);

    return 0;
}
