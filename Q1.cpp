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

// Program: Menu-driven DLL and CDLL operations (Insert, Delete, Search, Display)

// ================== Node Structure ==================
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Create a new node
Node* createNode(int value) {
    Node* n = new Node();
    n->data = value;
    n->next = n->prev = nullptr;
    return n;
}

// ================== Insertion ==================
void insertNode(Node*& head, int value, int mode, int ref = 0, bool isCircular = false) {
    Node* newNode = createNode(value);
    if (!head) { 
        head = newNode; 
        if (isCircular) head->next = head->prev = head;
        return;
    }

    Node* tail = isCircular ? head->prev : nullptr;

    // 1: Beginning
    if (mode == 1) {
        if (isCircular) {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    // 2: End
    else if (mode == 2) {
        if (isCircular) {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    // 3: After node
    else if (mode == 3) {
        Node* temp = head;
        do {
            if (temp->data == ref) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next) temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (isCircular && temp != head);
        cout << "Node " << ref << " not found.\n";
    }
    // 4: Before node
    else if (mode == 4) {
        Node* temp = head;
        do {
            if (temp->data == ref) {
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev) temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head) head = newNode;
                return;
            }
            temp = temp->next;
        } while (isCircular && temp != head);
        cout << "Node " << ref << " not found.\n";
    }
}

// ================== Deletion ==================
void deleteNode(Node*& head, int key, bool isCircular = false) {
    if (!head) return;
    Node* temp = head;
    Node* tail = isCircular ? head->prev : nullptr;

    if (temp->data == key) {
        if (isCircular) {
            if (temp->next == head) { delete head; head = nullptr; return; } // single node
            tail->next = head->next;
            head->next->prev = tail;
            head = head->next;
        } else {
            head = head->next;
            if (head) head->prev = nullptr;
        }
        delete temp;
        cout << "Node deleted.\n";
        return;
    }

    temp = temp->next;
    while (temp && (!isCircular || temp != head)) {
        if (temp->data == key) {
            temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node not found.\n";
}

// ================== Search ==================
void searchNode(Node* head, int key, bool isCircular = false) {
    if (!head) { cout << "List empty.\n"; return; }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) { cout << "Node " << key << " found at position " << pos << ".\n"; return; }
        temp = temp->next;
        pos++;
    } while (isCircular ? (temp != head) : (temp != nullptr));
    cout << "Node not found.\n";
}

// ================== Display ==================
void displayList(Node* head, bool isCircular = false) {
    if (!head) { cout << "List empty.\n"; return; }
    Node* temp = head;
    cout << (isCircular ? "CDLL: " : "DLL: ");
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (isCircular ? (temp != head) : (temp != nullptr));
    cout << (isCircular ? "(back to head)\n" : "NULL\n");
}

// ================== Free Memory ==================
void freeDLL(Node*& head) {
    Node* temp;
    while(head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void freeCDLL(Node*& head) {
    if (!head) return;
    Node* temp = head->next;
    while(temp != head) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    delete head;
    head = nullptr;
}

// ================== Main Menu ==================
int main() {
    Node* head = nullptr;
    bool isCircular;
    cout << "1. Doubly Linked List (DLL)\n2. Circular Doubly Linked List (CDLL)\nChoice: ";
    int ch; cin >> ch;
    isCircular = (ch == 2);

    while (true) {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert After Node\n4.Insert Before Node\n5.Delete Node\n6.Search Node\n7.Display\n8.Exit\nChoice: ";
        cin >> ch;
        if (ch == 8) break;

        int val, ref;
        switch (ch) {
            case 1: cout << "Value: "; cin >> val; insertNode(head, val, 1, 0, isCircular); break;
            case 2: cout << "Value: "; cin >> val; insertNode(head, val, 2, 0, isCircular); break;
            case 3: cout << "Value and after which node: "; cin >> val >> ref; insertNode(head, val, 3, ref, isCircular); break;
            case 4: cout << "Value and before which node: "; cin >> val >> ref; insertNode(head, val, 4, ref, isCircular); break;
            case 5: cout << "Node to delete: "; cin >> val; deleteNode(head, val, isCircular); break;
            case 6: cout << "Node to search: "; cin >> val; searchNode(head, val, isCircular); break;
            case 7: displayList(head, isCircular); break;
            default: cout << "Invalid choice.\n";
        }
    }

    // Free memory before exit
    if (isCircular) freeCDLL(head);
    else freeDLL(head);

    return 0;
}
