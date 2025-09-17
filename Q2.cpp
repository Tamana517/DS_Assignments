/*
Q2: Write a program to count the number of occurrences of a given key in a singly linked
list and then delete all the occurrences. For example, if given linked list is 1->2->1-
>2->1->3->1 and given key is 1, then output should be 4. After deletion of all the
occurrences of 1, the linked list is 2->2->3.
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Class for singly linked list operations
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

    // Count occurrences of a given key
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    // Delete all occurrences of a given key
    void deleteAllOccurrences(int key) {
        // Delete from beginning if matches
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }

    // Display the list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
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
    int n, value, key;

    cout << "Enter number of elements in the list: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Enter the key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Number of occurrences of " << key << " is: " << count << "\n";

    list.deleteAllOccurrences(key);

    cout << "List after deleting all occurrences of " << key << ":\n";
    list.displayList();

    return 0;
}
