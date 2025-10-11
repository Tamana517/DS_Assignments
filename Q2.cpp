/*
Display all the node values in a circular linked list, repeating value of head node at the
end too.
Input: 20 → 100 → 40 → 80 → 60,
Output: 20 100 40 80 60 20.
*/

#include <iostream>
using namespace std;

struct CLLNode {
    int data;
    CLLNode* next;
};

// ================== INSERT AT END (Optimized with Tail) ==================
void insertCLL(CLLNode*& head, CLLNode*& tail, int value) {
    CLLNode* newNode = new CLLNode{value, nullptr};
    if (!head) {
        head = tail = newNode;
        newNode->next = head; // circular link
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode; // update tail
}

// ================== DISPLAY CLL WITH HEAD REPEATED ==================
void displayCLL(CLLNode* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    CLLNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // repeat head at the end
}

// ================== MAIN ==================
int main() {
    CLLNode* head = nullptr;
    CLLNode* tail = nullptr; // keep track of last node
    int values[] = {20, 100, 40, 80, 60};

    // Insert all nodes
    for (int val : values)
        insertCLL(head, tail, val);

    // Display
    displayCLL(head); // Output: 20 100 40 80 60 20

    return 0;
}
