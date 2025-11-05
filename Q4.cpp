// Q4: Write a program to determine whether a given binary tree is a BST or not.

#include <iostream>
#include <climits>   // For INT_MIN and INT_MAX
using namespace std;

// Structure for a node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor: directly initializes data members using an initializer list
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert nodes (BST property maintained)
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Helper function that checks BST property using value range limits
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    // Current node must lie within [minVal, maxVal]
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Check left and right subtrees recursively
    return (isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal));
}

// Wrapper function that starts the BST check with the full integer range
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    // Check whether the tree is a BST
    if (isBST(root))
        cout << "\nThe given binary tree IS a Binary Search Tree (BST).\n";
    else
        cout << "\nThe given binary tree is NOT a Binary Search Tree.\n";

    return 0;
}
