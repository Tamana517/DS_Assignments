/*
Q3: Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output- 3
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

    // Find and print the middle node
    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element is: " << slow->data << "\n";
    }

    // Display the lis
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
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

    list.findMiddle();

    return 0;
}
