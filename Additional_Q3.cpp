/*
Q3: Given a binary tree, return its maximum depth. The depth of a binary tree is the number
of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of
the depths across all the paths.
Example:
Testing
Input Format
The first line contains an integer T denoting the number of test cases.
For each test case, the input has 2 lines:
The first line contains an integer n denoting the number of nodes in the tree (including the
NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The
integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output has an integer denoting the maximum depth of the tree.
Sample Input
5
12
1 2 3 4 5 6 -1 -1 -1 7 -1 8
7
1 2 -1 4 -1 5 6
7
8 -1 9 -1 10 11 12
5
28 14 11 -1 48
1
6
Expected Output
4
4
4
3
1
*/

// Time Complexity: O(n) – each node is processed once during tree construction and depth computation
// Space Complexity: O(n) – uses queue for tree construction and recursion stack for depth calculation

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

// Build a binary tree from level order traversal (where -1 represents NULL)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Recursive function to find the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nodes(n);

        // Read level-order input for the current test case
        for (int i = 0; i < n; i++)
            cin >> nodes[i];

        // Build tree and compute its maximum depth
        TreeNode* root = buildTree(nodes);
        cout << maxDepth(root) << endl;
    }

    return 0;
}
