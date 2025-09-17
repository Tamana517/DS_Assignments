/*
Q4: Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert node at the end
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
    }

    // Reverse the linked list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Display the list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
};

// Main function
int main() {
    SinglyLinkedList list;
    int n, value;

    cout << "Enter number of elements in the list: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Original list:\n";
    list.displayList();

    list.reverseList();

    cout << "Reversed list:\n";
    list.displayList();

    return 0;
}
