// Q4: Write a program to check if a doubly linked list of characters is palindrome or not.

#include <iostream>
using namespace std;

// Node structure for Doubly Linked List (DLL)
struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert node at the end
void insertEnd(Node*& head, char data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to check if DLL is palindrome
bool isPalindrome(Node* head) {
    if (!head) return true; // Empty list is palindrome

    Node* left = head;
    Node* right = head;
    
    // Move right to the last node
    while (right->next)
        right = right->next;

    // Compare from both ends
    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

// Function to display the DLL
void display(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    string str;

    cout << "Enter a string to create DLL: ";
    cin >> str;

    // Insert characters into DLL
    for (char c : str) {
        insertEnd(head, c);
    }

    cout << "Doubly Linked List: ";
    display(head);

    // Check palindrome
    if (isPalindrome(head))
        cout << "The DLL is a palindrome." << endl;
    else
        cout << "The DLL is not a palindrome." << endl;

    return 0;
}
