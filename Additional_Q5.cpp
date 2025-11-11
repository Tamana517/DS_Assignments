// Q5:  Given preorder and in-order traversals, write a program to construct the Binary Tree

// Time Complexity: O(n) – each node is processed once, and map lookups take O(1) time each
// Space Complexity: O(n) – for the unordered_map and recursion stack in worst case

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to construct the tree recursively
TreeNode* buildTreeHelper(const vector<int>& preorder, int preStart, int preEnd,
                          const vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int,int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    int rootVal = preorder[preStart];        // Root is first element in preorder
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];             // Index of root in inorder
    int leftSize = inRoot - inStart;         // Number of nodes in left subtree

    // Recurse for left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSize,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + leftSize + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// Main function to build tree from preorder and inorder
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    unordered_map<int,int> inMap; // Value -> index mapping for inorder
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

// Function to print preorder (for testing)
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Function to print inorder (for testing)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "\nPreorder of constructed tree: ";
    printPreorder(root);  // Should match original preorder
    cout << "Inorder of constructed tree: ";
    printInorder(root);   // Should match original inorder
    cout << endl;

    return 0;
}
