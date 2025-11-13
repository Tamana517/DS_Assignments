/*
Q4: There are different ways to look at a binary tree. The right view of a binary tree contains
the set of nodes that will be visible if you look at the binary tree from the right side. Given
the root node of a binary tree, return an array containing the node elements in the right view,
from top to bottom.
Testing
Input Format
The first line contains an integer T denoting the number of test cases.
For each test case, the input has 2 lines:
The first line contains an integer n denoting the number of nodes in the tree (including the
NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The
integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with space-separated integers representing the
right view of the binary tree.
Sample Input
6
7
1 2 -1 4 -1 5 6
3
6 -1 4
7
8 -1 9 -1 10 11 12
5
28 14 11 -1 48
1
6
7
3 -1 2 1 5 -1 6
Expected Output
1 2 4 6
6 4
8 9 10 12
28 11 48
6
3 2 5 6
*/

// Time Complexity: O(n) - each node is processed once during tree construction and right view traversal.
// Space Complexity: O(n) - queue stores nodes of each level; in worst case, all nodes at one level.

#include <iostream>
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Build binary tree from level order input (-1 indicates NULL)
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    // Construct tree using level order traversal
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        // Assign left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Assign right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Compute right view of the binary tree
vector<int> rightView(Node* root) {
    vector<int> view;
    if (!root) return view;

    queue<Node*> q;
    q.push(root);

    // Level order traversal
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // Last node of each level forms the right view
            if (i == size - 1)
                view.push_back(curr->data);

            // Push left and right children if they exist
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return view;
}

int main() {
    // Driver code: process multiple test cases and print right view for each
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Node* root = buildTree(arr);
        vector<int> ans = rightView(root);

        // Output the right view for this test case
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size() - 1)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
