/*
Q2: Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST
*/

#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor: directly initializes data members
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class representing Binary Search Tree
class BST {
private:
    Node* root;

    // Recursive insert function
    Node* insert(Node* root, int value) {
        if (root == nullptr)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
        return root;
    }

    //  Recursive inorder traversal
    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    // (a) Recursive search
    Node* searchRecursive(Node* root, int key) {
        if (root == nullptr || root->data == key)
            return root;

        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    // (b) Maximum element (rightmost node)
    Node* findMax(Node* root) {
        while (root && root->right != nullptr)
            root = root->right;
        return root;
    }

    // (c) Minimum element (leftmost node)
    Node* findMin(Node* root) {
        while (root && root->left != nullptr)
            root = root->left;
        return root;
    }

public:
    BST() : root(nullptr) {}

    // Insert public function
    void insert(int value) {
        root = insert(root, value);
    }

    // Display BST in inorder
    void display() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // (a) Search - Recursive version
    void searchRecursive(int key) {
        Node* result = searchRecursive(root, key);
        if (result)
            cout << "Element " << key << " found (Recursive Search)." << endl;
        else
            cout << "Element " << key << " not found (Recursive Search)." << endl;
    }

    // (a) Search - Non-Recursive version
    void searchNonRecursive(int key) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == key) {
                cout << "Element " << key << " found (Non-Recursive Search)." << endl;
                return;
            }
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        cout << "Element " << key << " not found (Non-Recursive Search)." << endl;
    }

    // (b) Display maximum element
    void showMax() {
        Node* maxNode = findMax(root);
        if (maxNode)
            cout << "Maximum element in BST: " << maxNode->data << endl;
        else
            cout << "BST is empty." << endl;
    }

    // (c) Display minimum element
    void showMin() {
        Node* minNode = findMin(root);
        if (minNode)
            cout << "Minimum element in BST: " << minNode->data << endl;
        else
            cout << "BST is empty." << endl;
    }

    // (d) Inorder Successor of a given node
    void inorderSuccessor(int key) {
        Node* current = root;
        Node* successor = nullptr;

        // Search for the node
        while (current != nullptr) {
            if (key < current->data) {
                successor = current;
                current = current->left;
            }
            else if (key > current->data) {
                current = current->right;
            }
            else
                break;
        }

        if (current == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        // If right subtree exists, successor is the smallest node in right subtree
        if (current->right != nullptr)
            successor = findMin(current->right);

        if (successor)
            cout << "Inorder Successor of " << key << " is " << successor->data << endl;
        else
            cout << "No Inorder Successor exists for " << key << endl;
    }

    // (e) Inorder Predecessor of a given node
    void inorderPredecessor(int key) {
        Node* current = root;
        Node* predecessor = nullptr;

        // Search for the node
        while (current != nullptr) {
            if (key > current->data) {
                predecessor = current;
                current = current->right;
            }
            else if (key < current->data) {
                current = current->left;
            }
            else
                break;
        }

        if (current == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        // If left subtree exists, predecessor is the largest node in left subtree
        if (current->left != nullptr)
            predecessor = findMax(current->left);

        if (predecessor)
            cout << "Inorder Predecessor of " << key << " is " << predecessor->data << endl;
        else
            cout << "No Inorder Predecessor exists for " << key << endl;
    }

    

    
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    BST tree;
    int choice, value;

    cout << "Binary Search Tree Operations\n";
    cout << "1. Insert\n2. Display (Inorder)\n3. Search (Recursive)\n4. Search (Non-Recursive)\n";
    cout << "5. Maximum Element\n6. Minimum Element\n7. Inorder Successor\n8. Inorder Predecessor\n9. Exit\n";

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
                tree.display();
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                tree.searchRecursive(value);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                tree.searchNonRecursive(value);
                break;
            case 5:
                tree.showMax();
                break;
            case 6:
                tree.showMin();
                break;
            case 7:
                cout << "Enter node value: ";
                cin >> value;
                tree.inorderSuccessor(value);
                break;
            case 8:
                cout << "Enter node value: ";
                cin >> value;
                tree.inorderPredecessor(value);
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 9);

    return 0;
}
