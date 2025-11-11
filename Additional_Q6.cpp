// Q6. Given in-order and post-order traversals, write a program to construct the Binary Tree.

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
TreeNode* buildTreeHelper(const vector<int>& inorder, int inStart, int inEnd,
                          const vector<int>& postorder, int postStart, int postEnd,
                          unordered_map<int,int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;

    int rootVal = postorder[postEnd];        // Root is last element in postorder
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];             // Index of root in inorder
    int leftSize = inRoot - inStart;         // Number of nodes in left subtree

    // Recurse for left and right subtrees
    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                 postorder, postStart, postStart + leftSize - 1, inMap);
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                  postorder, postStart + leftSize, postEnd - 1, inMap);

    return root;
}

// Main function to build tree from inorder and postorder
TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
    unordered_map<int,int> inMap; // Value -> index mapping for inorder
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, inMap);
}

// Function to print inorder (for testing)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to print postorder (for testing)
void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> inorder   = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "\nInorder of constructed tree: ";
    printInorder(root);    // Should match original inorder
    cout << "\nPostorder of constructed tree: ";
    printPostorder(root);  // Should match original postorder
    cout << endl;

    return 0;
}
