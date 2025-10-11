/*
Q1: Develop a menu driven program for the following operations of on a Circular as well
as a Doubly Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.
*/

#include <iostream>
using namespace std;

// =================== DLL NODE ===================
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

// =================== CLL NODE ===================
struct CLLNode {
    int data;
    CLLNode* next;
};

// =================== DLL FUNCTIONS ===================
DLLNode* createDLLNode(int value) {
    DLLNode* n = new DLLNode();
    n->data = value;
    n->next = n->prev = nullptr;
    return n;
}

void insertDLL(DLLNode*& head, int value, int posAfter = -1) {
    DLLNode* newNode = createDLLNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    if (posAfter == -1) { // insert at beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    // insert after specific node
    DLLNode* temp = head;
    while (temp && temp->data != posAfter) temp = temp->next;
    if (!temp) {
        cout << "Node " << posAfter << " not found.\n";
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteDLL(DLLNode*& head, int key) {
    if (!head) return;
    DLLNode* temp = head;
    if (temp->data == key) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        cout << "Node deleted.\n";
        return;
    }
    temp = head->next;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { cout << "Node not found.\n"; return; }
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    cout << "Node deleted.\n";
}

void searchDLL(DLLNode* head, int key) {
    DLLNode* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) { cout << "Node found at position " << pos << endl; return; }
        temp = temp->next; pos++;
    }
    cout << "Node not found.\n";
}

void displayDLL(DLLNode* head) {
    if (!head) { cout << "List empty.\n"; return; }
    cout << "DLL: ";
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

// =================== CLL FUNCTIONS ===================
CLLNode* createCLLNode(int value) {
    CLLNode* n = new CLLNode();
    n->data = value;
    n->next = nullptr;
    return n;
}

void insertCLL(CLLNode*& head, int value, int posAfter = -1) {
    CLLNode* newNode = createCLLNode(value);
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    if (posAfter == -1) { // insert at beginning
        CLLNode* tail = head;
        while (tail->next != head) tail = tail->next;
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        return;
    }
    // insert after specific node
    CLLNode* temp = head;
    do {
        if (temp->data == posAfter) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node " << posAfter << " not found.\n";
}

void deleteCLL(CLLNode*& head, int key) {
    if (!head) return;
    CLLNode* temp = head;
    CLLNode* prev = nullptr;

    // single node
    if (head->data == key && head->next == head) { delete head; head = nullptr; cout << "Node deleted.\n"; return; }

    // delete head
    if (head->data == key) {
        prev = head;
        while (prev->next != head) prev = prev->next;
        CLLNode* delNode = head;
        head = head->next;
        prev->next = head;
        delete delNode;
        cout << "Node deleted.\n";
        return;
    }

    prev = head;
    temp = head->next;
    while (temp != head) {
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Node not found.\n";
}

void searchCLL(CLLNode* head, int key) {
    if (!head) { cout << "List empty.\n"; return; }
    CLLNode* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) { cout << "Node found at position " << pos << endl; return; }
        temp = temp->next; pos++;
    } while (temp != head);
    cout << "Node not found.\n";
}

void displayCLL(CLLNode* head) {
    if (!head) { cout << "List empty.\n"; return; }
    cout << "CLL: ";
    CLLNode* temp = head;
    do { cout << temp->data << " "; temp = temp->next; } while (temp != head);
    cout << endl;
}

// =================== MAIN MENU ===================
int main() {
    DLLNode* dllHead = nullptr;
    CLLNode* cllHead = nullptr;
    int choice, subChoice, value, key, afterValue;

    do {
        cout << "\n--- MENU ---\n1. Doubly Linked List\n2. Circular Linked List\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 0) break;

        do {
            cout << "\n1.Insert at beginning\n2.Insert at end\n3.Insert after node\n4.Delete node\n5.Search node\n6.Display\n0.Back\nChoice: ";
            cin >> subChoice;

            switch (subChoice) {
            case 1:
                cout << "Value: "; cin >> value;
                if (choice == 1) insertDLL(dllHead, value);
                else insertCLL(cllHead, value);
                break;
            case 2:
                cout << "Value: "; cin >> value;
                if (choice == 1) { cout << "After which node to insert at end (-1 for last)? "; cin >> afterValue; insertDLL(dllHead, value, -2); }
                else { cout << "After which node to insert at end (-1 for last)? "; cin >> afterValue; insertCLL(cllHead, value, -2); }
                break;
            case 3:
                cout << "Value: "; cin >> value; cout << "After node: "; cin >> afterValue;
                if (choice == 1) insertDLL(dllHead, value, afterValue);
                else insertCLL(cllHead, value, afterValue);
                break;
            case 4:
                cout << "Node to delete: "; cin >> key;
                if (choice == 1) deleteDLL(dllHead, key);
                else deleteCLL(cllHead, key);
                break;
            case 5:
                cout << "Node to search: "; cin >> key;
                if (choice == 1) searchDLL(dllHead, key);
                else searchCLL(cllHead, key);
                break;
            case 6:
                if (choice == 1) displayDLL(dllHead);
                else displayCLL(cllHead);
                break;
            case 0: break;
            default: cout << "Invalid choice\n";
            }
        } while (subChoice != 0);

    } while (choice != 0);

    return 0;
}
