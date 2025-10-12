/*
Q5: Given a 2D matrix, the task is to convert it into a doubly-linked list with four pointers
that are next, previous, up, and down, each node of this list should be connected to its
next, previous, up, and down nodes.
*/

// Time Complexity:O(m*n), Space Complexity:O(m*n), where m = Number of columns and n = Number of rows

#include <iostream>
using namespace std;

// Node structure for the 4-pointer doubly linked list
struct Node {
    int data;
    Node *right, *left, *up, *down;
    Node(int val) {
        data = val;
        right = left = up = down = nullptr;
    }
};

// Function to construct 2D doubly linked list from matrix
Node* constructDLL(int mat[3][3], int n, int m) {
    Node* head = nullptr;
    Node* prevRow[m] = {nullptr};   // stores nodes of previous row (O(m) auxiliary space)

    for (int i = 0; i < n; i++) {
        Node* prev = nullptr;       // pointer to previous node in current row
        for (int j = 0; j < m; j++) {
            Node* curr = new Node(mat[i][j]);

            // Link to left node (same row)
            if (prev) {
                prev->right = curr;
                curr->left = prev;
            }

            // Link to upper node (previous row)
            if (prevRow[j]) {
                prevRow[j]->down = curr;
                curr->up = prevRow[j];
            }

            // Update prevRow for next iteration
            prevRow[j] = curr;

            // Set head (top-left node)
            if (i == 0 && j == 0)
                head = curr;

            prev = curr; // move to next column
        }
    }
    return head;
}

// Function to display the 2D doubly linked list row-wise
void display(Node* head) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

// Driver Code
int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = constructDLL(mat, 3, 3);

    cout << "2D Doubly Linked List representation:\n";
    display(head);

    return 0;
}
