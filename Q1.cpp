/*
Q1: Develop a menu driven program for the following operations of on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values
*/

#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

// Class to perform all operations on singly linked list
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // Insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

    // Insert before or after a node with specific value
    void insertInBetween(int value, int target, bool before) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << target << " not found.\n";
            delete newNode;
            return;
        }

        if (before) {
            if (temp == head) {
                newNode->next = head;
                head = newNode;
            } else {
                prev->next = newNode;
                newNode->next = temp;
            }
            cout << value << " inserted before " << target << ".\n";
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted after " << target << ".\n";
        }
    }

    // Delete node from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // Delete node from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        cout << temp->data << " deleted from end.\n";
        delete temp;
    }

    // Delete a specific node by value
    void deleteSpecificNode(int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            cout << target << " deleted.\n";
            delete temp;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        prev->next = temp->next;
        cout << target << " deleted.\n";
        delete temp;
    }

    // Search for a node and display its position
    void searchNode(int value) {
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node " << value << " not found.\n";
    }

    // Display all nodes in the list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function with menu-driven interface
int main() {
    SinglyLinkedList list;
    int choice, value, target;
    bool before;

    do {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a specific node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search for a node\n";
        cout << "8. Display all nodes\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter the target node value: ";
            cin >> target;
            cout << "Insert before (1) or after (0): ";
            cin >> before;
            list.insertInBetween(value, target, before);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter node value to delete: ";
            cin >> target;
            list.deleteSpecificNode(target);
            break;
        case 7:
            cout << "Enter node value to search: ";
            cin >> value;
            list.searchNode(value);
            break;
        case 8:
            list.displayList();
            break;
        case 9:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
