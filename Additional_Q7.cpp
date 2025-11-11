/*
Q7: Write a program to merge two BSTs into a doubly-linked list in sorted order.
Example Input:
     20
T1:  / \
   10  30
       / \
      25 100
     50
T2  / \
   5  70
Output:
5 <—> 10 <—> 20 <—> 25 <—> 30 <—> 50 <—> 70 <—> 100 <—> null
*/

// Time Complexity:  O(m + n), where m = nodes in BST1, n = nodes in BST2
// Space Complexity: O(m + n) overall (includes DLL nodes + O(h1 + h2) recursion stack from BST to DLL conversion)

#include <iostream>
using namespace std;

// Definition for Binary Search Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Definition for Doubly Linked List Node
struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// Convert BST to sorted DLL (inorder traversal)
void BSTToDLL(TreeNode* root, DLLNode*& head, DLLNode*& tail) {
    if (!root) return;

    // Process left subtree
    BSTToDLL(root->left, head, tail);

    // Create DLL node for current BST node
    DLLNode* node = new DLLNode(root->val);
    if (!head) {          // first node in DLL
        head = tail = node;
    } else {              // link current node to previous
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    // Process right subtree
    BSTToDLL(root->right, head, tail);
}

// Merge two sorted DLLs
DLLNode* mergeDLL(DLLNode* head1, DLLNode* head2) {
    DLLNode dummy(0);  // dummy node simplifies merge
    DLLNode* tail = &dummy;

    while (head1 && head2) {
        if (head1->val < head2->val) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (head1) { tail->next = head1; head1->prev = tail; }
    if (head2) { tail->next = head2; head2->prev = tail; }

    DLLNode* mergedHead = dummy.next;
    if (mergedHead) mergedHead->prev = nullptr;

	// Return head of merged DLL
    return mergedHead;
}

// Print DLL in required format
void printDLL(DLLNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> null" << endl;
}

// Delete DLL nodes to free memory
void deleteDLL(DLLNode* head) {
    DLLNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Delete BST nodes to free memory
void deleteBST(TreeNode* root) {
    if (!root) return;
    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

int main() {
    // Example BST 1
    TreeNode* T1 = new TreeNode(20);
    T1->left = new TreeNode(10);
    T1->right = new TreeNode(30);
    T1->right->left = new TreeNode(25);
    T1->right->right = new TreeNode(100);

    // Example BST 2
    TreeNode* T2 = new TreeNode(50);
    T2->left = new TreeNode(5);
    T2->right = new TreeNode(70);

    // Convert BSTs to DLLs
    DLLNode *head1 = nullptr, *tail1 = nullptr;
    DLLNode *head2 = nullptr, *tail2 = nullptr;
    BSTToDLL(T1, head1, tail1);
    BSTToDLL(T2, head2, tail2);

    // Merge DLLs
    DLLNode* mergedHead = mergeDLL(head1, head2);

    // Print merged DLL
    printDLL(mergedHead);

    // Free allocated memory
    deleteDLL(mergedHead);
    deleteBST(T1);
    deleteBST(T2);

    return 0;
}
