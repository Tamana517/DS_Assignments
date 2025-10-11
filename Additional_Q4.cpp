/*
Q4: Given a doubly linked list having exactly one of the node pointing to a random node in the
list, the task is to correct this random pointer in the doubly linked list, such that it points to
the expected node.
*/

//Time Complexity: O(n^2), Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;
};

// Function to correct random pointer
void correctRandomPointer(Node* head) {
    vector<Node*> nodes;
    Node* curr = head;
    
    // Store nodes in an array
    while (curr) {
        nodes.push_back(curr);
        curr = curr->next;
    }

    // For each node, check if random pointer is correct
    for (auto node : nodes) {
        if (node->random) {
            bool found = false;
            for (auto n : nodes) {
                if (n->data == node->random->data) {
                    found = true;
                    break;
                }
            }
            // If random is incorrect
            if (!found) {
                // Correct it (example: point to the first node)
                node->random = nodes[0];  // Replace with logic for expected node
            }
        }
    }
}

// Helper function to print list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Data: " << curr->data;
        if (curr->random)
            cout << ", Random: " << curr->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        curr = curr->next;
    }
}
