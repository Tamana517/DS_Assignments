/*
Q2: Given an integer n, return all the structurally unique BST's (binary search trees), which
has exactly n nodes of unique values from 1 to n. Return the answer in any order.
Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:
Input: n = 1
Output: [[1]]
Constraints:
1 <= n <= 8
*/

// Time Complexity: O(n * number of unique BSTs) – each unique tree is created once
// Space Complexity: O(n) – recursion depth in the worst case (skewed tree)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Builds all possible BSTs for the given range of values
vector<TreeNode*> buildAllTrees(int startVal, int endVal) {
    vector<TreeNode*> treeList;

    // Base case: if the range is invalid, return a list containing null
    if (startVal > endVal) {
        treeList.push_back(nullptr);
        return treeList;
    }

    // Select each value as a possible root node
    for (int rootValue = startVal; rootValue <= endVal; rootValue++) {
        // Recursively construct all possible left and right subtrees
        vector<TreeNode*> leftSubtrees  = buildAllTrees(startVal, rootValue - 1);
        vector<TreeNode*> rightSubtrees = buildAllTrees(rootValue + 1, endVal);

        // Connect each pair of left and right subtrees with the current root
        for (TreeNode* leftRoot : leftSubtrees) {
            for (TreeNode* rightRoot : rightSubtrees) {
                TreeNode* root = new TreeNode(rootValue);
                root->left = leftRoot;
                root->right = rightRoot;
                treeList.push_back(root);
            }
        }
    }

    return treeList;
}

// Wrapper function to generate all unique BSTs storing values 1 to n
vector<TreeNode*> generateUniqueBSTs(int n) {
    if (n == 0) return {};
    return buildAllTrees(1, n);
}

// Serializes a BST into level-order representation with "null" for empty nodes
vector<string> serializeBST(TreeNode* root) {
    vector<string> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing "null" entries for a cleaner format
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    return result;
}

int main() {
    int n;
    cout << "Enter n = ";
    cin >> n;

    // Validate input based on constraints
    if (n < 1 || n > 8) {
        cout << "Invalid input. n must be between 1 and 8." << endl;
        return 0;
    }
  
    // Generate all structurally unique BSTs for the given n
    vector<TreeNode*> allBSTs = generateUniqueBSTs(n);

    // Display each tree in level-order list format
    cout << "[";
    for (size_t i = 0; i < allBSTs.size(); i++) {
        vector<string> serialized = serializeBST(allBSTs[i]);
        cout << "[";
        for (size_t j = 0; j < serialized.size(); j++) {
            cout << serialized[j];
            if (j + 1 < serialized.size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < allBSTs.size()) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
