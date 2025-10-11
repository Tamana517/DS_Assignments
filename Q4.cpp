// Q4: Write a program to check if a doubly linked list of characters is palindrome or not.

#include <iostream>
using namespace std;

// ====================== Node Structure for Doubly Linked List ======================
struct Node {
    char data;
    Node* next;
    Node* prev;
};

// ====================== Create a New Node ======================
// Allocates memory for a new node and initializes it
Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// ====================== Insert Node at End ======================
// Inserts a new node with the given data at the end of the DLL
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

// ====================== Check if DLL is Palindrome ======================
// Returns true if the DLL is a palindrome, false otherwise
bool isPalindrome(Node* head) {
    if (!head) return true; // Empty list is palindrome

    Node* left = head;
    Node* right = head;
    
    // Move right pointer to the last node
    while (right->next)
        right = right->next;

    // Compare nodes from both ends
    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

// ====================== Display Doubly Linked List ======================
void display(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// ====================== Main Function ======================
int main() {
    Node* head = nullptr;
    string str;

    cout << "Enter a string to create DLL: ";
    cin >> str;

    // Insert each character of the string into the DLL
    for (char c : str) {
        insertEnd(head, c);
    }

    // Display the DLL
    cout << "Doubly Linked List: ";
    display(head);

    // Check if the DLL is a palindrome
    if (isPalindrome(head))
        cout << "The DLL is a palindrome." << endl;
    else
        cout << "The DLL is not a palindrome." << endl;

    return 0;
}
