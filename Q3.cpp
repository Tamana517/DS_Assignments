#include <iostream>
using namespace std;

// ====================== Doubly Linked List ======================
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

DLLNode* dllHead = nullptr;

// Insert at end
void insertDLL(int value) {
    DLLNode* newNode = new DLLNode{value, nullptr, nullptr};
    if (!dllHead) {
        dllHead = newNode;
        return;
    }
    DLLNode* temp = dllHead;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node with specific value (first occurrence)
void deleteDLL(int value) {
    DLLNode* temp = dllHead;
    while (temp) {
        if (temp->data == value) {
            if (temp->prev) temp->prev->next = temp->next;
            else dllHead = temp->next; // deleting head

            if (temp->next) temp->next->prev = temp->prev;

            delete temp;
            cout << "Node " << value << " deleted.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node " << value << " not found.\n";
}

// Size
int sizeDLL() {
    int count = 0;
    DLLNode* temp = dllHead;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display
void displayDLL() {
    if (!dllHead) { cout << "Doubly Linked List is empty.\n"; return; }
    DLLNode* temp = dllHead;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ====================== Circular Linked List ======================
struct CLLNode {
    int data;
    CLLNode* next;
};

CLLNode* cllHead = nullptr;
CLLNode* cllTail = nullptr;

// Insert at end
void insertCLL(int value) {
    CLLNode* newNode = new CLLNode{value, nullptr};
    if (!cllHead) {
        cllHead = cllTail = newNode;
        newNode->next = cllHead; // circular
        return;
    }
    cllTail->next = newNode;
    newNode->next = cllHead;
    cllTail = newNode;
}

// Delete a node with specific value (first occurrence)
void deleteCLL(int value) {
    if (!cllHead) { cout << "Circular Linked List is empty.\n"; return; }

    CLLNode* curr = cllHead;
    CLLNode* prev = cllTail;
    do {
        if (curr->data == value) {
            if (curr == cllHead) cllHead = cllHead->next;
            if (curr == cllTail) cllTail = prev;

            prev->next = curr->next;
            delete curr;
            cout << "Node " << value << " deleted.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != cllHead);

    cout << "Node " << value << " not found.\n";
}

// Size
int sizeCLL() {
    if (!cllHead) return 0;
    int count = 1;
    CLLNode* temp = cllHead->next;
    while (temp != cllHead) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display
void displayCLL() {
    if (!cllHead) { cout << "Circular Linked List is empty.\n"; return; }
    CLLNode* temp = cllHead;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != cllHead);
    cout << cllHead->data << " (head repeated)\n";
}

// ====================== Main Menu ======================
int main() {
    int choice, value;

    while (true) {
        cout << "\nSelect List Type:\n";
        cout << "1. DLL (Doubly Linked List)\n";
        cout << "2. CLL (Circular Linked List)\n";
        cout << "3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 3) break;

        if (choice == 1) { // DLL menu
            int op;
            cout << "DLL (Doubly Linked List) Operations:\n";
            cout << "1. Insert\n2. Delete\n3. Display\n4. Size\nChoice: ";
            cin >> op;

            switch(op) {
                case 1:
                    cout << "Enter value to insert: "; cin >> value;
                    insertDLL(value);
                    break;
                case 2:
                    cout << "Enter value to delete: "; cin >> value;
                    deleteDLL(value);
                    break;
                case 3: displayDLL(); break;
                case 4: cout << "Size: " << sizeDLL() << endl; break;
                default: cout << "Invalid!\n";
            }
        }
        else if (choice == 2) { // CLL menu
            int op;
            cout << "CLL (Circular Linked List) Operations:\n";
            cout << "1. Insert\n2. Delete\n3. Display\n4. Size\nChoice: ";
            cin >> op;

            switch(op) {
                case 1:
                    cout << "Enter value to insert: "; cin >> value;
                    insertCLL(value);
                    break;
                case 2:
                    cout << "Enter value to delete: "; cin >> value;
                    deleteCLL(value);
                    break;
                case 3: displayCLL(); break;
                case 4: cout << "Size: " << sizeCLL() << endl; break;
                default: cout << "Invalid!\n";
            }
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    cout << "Program terminated.\n";
    return 0;
}
