/*
Q1: Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor: directly initializes data members using an initializer list
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new value into the BST
Node* insert(Node* root, int value) {
    // Base case: found an empty spot -> create a new node
    if (root == nullptr)
        return new Node(value);

    // Recursive case: go to left or right subtree
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    // Duplicates are ignored automatically

    return root; // Return unchanged root pointer
}

// Recursive Pre-order Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive In-order Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive Post-order Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}
