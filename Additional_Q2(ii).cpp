/*
Q2(ii): Given a Circular linked list containing N nodes, the task is
to remove all the nodes from list which contain elements whose parity is even. 
Note: Parity means no of 1 in binary form
11 -> 1011, parity = 3
15 -> 1111, parity = 4
Example:
Input: CLL: 9 -> 11 -> 34 -> 6 -> 13 -> 21
Output: 11 -> 13 -> 21
*/

// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
using namespace std;

// Node for CLL
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
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

// Insert node at end using tail pointer
void insert(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) { // empty list
        head = newNode;
        tail = newNode;
        newNode->next = head; // circular
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode; // update tail
}

// Remove nodes with even parity
void removeEvenParity(Node*& head, Node*& tail) {
    if (!head) return;

    Node* curr = head;
    Node* prev = tail;
    bool firstPass = true;

    do {
        Node* nextNode = curr->next;
        if (countParity(curr->data) == 0) { // even parity
            if (curr == head) { // removing head
                head = head->next;
                tail->next = head;
                delete curr;
                curr = head;
                if (head == nullptr) { tail = nullptr; return; }
                if (head == tail) firstPass = false; // one node left
            } else if (curr == tail) { // removing tail
                prev->next = head;
                delete curr;
                tail = prev;
            } else { // middle node
                prev->next = curr->next;
                delete curr;
            }
        } else {
            prev = curr;
        }
        curr = nextNode;
        if (curr == head && !firstPass) break;
        firstPass = false;
    } while (curr != head);
}

// Print CLL
void printCLL(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << " -> ";
    } while (temp != head);
    cout << endl;
}

// Main
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insert(head, tail, 9);
    insert(head, tail, 11);
    insert(head, tail, 34);
    insert(head, tail, 6);
    insert(head, tail, 13);
    insert(head, tail, 21);

    removeEvenParity(head, tail);

    cout << "CLL after removing even parity nodes: ";
    printCLL(head);

    return 0;
}
