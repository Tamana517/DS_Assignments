/*
Q1: Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no
children. A left leaf is a leaf that is the left child of another node.
Example:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
*/

// Time Complexity: O(n), as each node is visited once
// Space Complexity: O(h), recursion stack depends on tree height (O(log n) for balanced, O(n) for skewed)

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if a node is a leaf
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

// Function to sum all left leaves in the tree
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;

    // Check left child
    if (root->left) {
        if (isLeaf(root->left))
            sum += root->left->val;          // Add if left child is a leaf
        else
            sum += sumOfLeftLeaves(root->left); // Recurse if not a leaf
    }

    // Recurse right child
    if (root->right)
        sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Example usage
int main() {
    // Create binary tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of left leaves: " << sumOfLeftLeaves(root) << endl; // Output: 24

    return 0;
}
