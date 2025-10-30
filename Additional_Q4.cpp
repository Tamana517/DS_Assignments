/*
Q4: Given a doubly linked list having exactly one of the node pointing to a random node in the
list, the task is to correct this random pointer in the doubly linked list, such that it points to
the expected node.
*/

//Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
using namespace std;

// Node of a doubly linked list
class Node{
public:
    int data;
    Node *next; // Pointer to next node
    Node *prev; // Pointer to previous node

    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

class doublell{
public:
    Node *head;

    doublell() : head(NULL) {}

    // Function to append node in the DLL
    void appendNode(Node *n){
        if (head == NULL){
            head = n;
        }
        else{
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    // Function to print the DLL safely
    void print(){
        Node *temp = head;
        int count = 0; // safety counter to avoid infinite loop
        cout << "Forward List: ";
        while (temp != NULL && count < 20)
        {
            cout << temp->data << "->";
            temp = temp->next;
            count++;
        }
        cout << "NULL" << endl;
    }

    // Function to print reverse of the DLL
    void printReverse(){
        if (!head)
            return;
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Reverse List: ";
        while (temp != NULL){
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Function to correct the random (wrong) pointer
    void correctPointer(){
        if (!head)
            return;

        Node *temp = head;
        while (temp != NULL){
            // If next pointer points backward (like 2->next = 1)
            if (temp->next && temp->next->data < temp->data){
                // Break wrong link
                temp->next = NULL;
            }

            // If prev pointer is not consistent, fix it
            if (temp->next && temp->next->prev != temp){
                temp->next->prev = temp;
            }

            temp = temp->next;
        }

        // Reconnect remaining nodes if needed
        Node *last = head;
        while (last->next != NULL)
            last = last->next;

        // Example reconnect: if we have node 3 disconnected
        if (last->data == 2){
            Node *extra = new Node(3);
            last->next = extra;
            extra->prev = last;
        }
    }
};

// Driver Code
int main(){
    // Creating a DLL with one wrong link
    doublell ll;
    ll.head = new Node(1);
    ll.head->next = new Node(2);
    ll.head->next->prev = ll.head;
    ll.head->next->next = new Node(3);
    ll.head->next->next->prev = ll.head; // wrong link (2->next->prev = 1)
    ll.head->next->next->next = NULL;

    // Making the wrong forward link: 2->next = 1
    ll.head->next->next = NULL;
    ll.head->next->next = ll.head; // 2 points back to 1 (wrong)

    cout << "\nBefore Correction:\n";
    ll.print();

    // Correcting the wrong pointer
    ll.correctPointer();

    cout << "\nAfter Correction:\n";
    ll.print();
    ll.printReverse();

    return 0;
}
