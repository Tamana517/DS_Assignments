/*
Q3: Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST,
(d) Minimum depth of BST.
*/

#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor: directly initializes data members using an initializer list
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class representing Binary Search Tree
class BST {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insert(Node* root, int value) {
        if (root == nullptr)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
        // Duplicate values are ignored
        return root;
    }

    // Helper function to find the minimum value node
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* root, int value) {
        if (root == nullptr)
            return root;

        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else {
            // Node found
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children – replace with inorder successor (smallest in right subtree)
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Function to calculate maximum depth of BST
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }

    // Function to calculate minimum depth of BST
    int minDepth(Node* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;

        if (root->left == nullptr)
            return 1 + minDepth(root->right);

        if (root->right == nullptr)
            return 1 + minDepth(root->left);

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
    }

    // Inorder traversal for displaying BST
    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

public:
    BST() : root(nullptr) {}

    // (a) Insert an element
    void insert(int value) {
        root = insert(root, value);
    }

    // (b) Delete an existing element
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Display BST in inorder form
    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // (c) Maximum depth of BST
    void showMaxDepth() {
        cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    }

    // (d) Minimum depth of BST
    void showMinDepth() {
        cout << "Minimum Depth of BST: " << minDepth(root) << endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    cout << "Binary Search Tree Operations\n";
    cout << "1. Insert\n2. Delete\n3. Display (Inorder)\n4. Maximum Depth\n5. Minimum Depth\n6. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteValue(value);
                break;
            case 3:
                tree.display();
                break;
            case 4:
                tree.showMaxDepth();
                break;
            case 5:
                tree.showMinDepth();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
