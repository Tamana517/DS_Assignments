/*
Q1: Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
The lists may vary in length and have distinct nodes at the beginning, but from the point of
intersection onward, they share the same sequence of nodes. The task is to identify the first
common node where the two lists converge. If the two linked lists have no intersection at all,
return null. 
*/

// Time Complexity: O(m+n), where m = length of list A, n = length of list B
//Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// returns the intersection node if exists
Node* getIntersection(Node* headA, Node* headB) {
    if (!headA || !headB) return NULL;
    Node *p1 = headA, *p2 = headB;
    // when one pointer reaches end, shift it to other list
    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }
    return p1;
}

int main() {
    // listA: 4 -> 1 \
    //                 8 -> 5 -> NULL
    // listB: 5 -> 6 -> 1 /

    // common part
    Node* inter = new Node(8);
    inter->next = new Node(5);

    // list A
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = inter;

    // list B
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = inter;

    Node* ans = getIntersection(headA, headB);
    if (ans)
        cout << "Intersected at " << ans->data << endl;
    else
        cout << "No intersection" << endl;

    // free memory for listA nodes before intersection
    delete headA->next;
    delete headA;
    // free memory for listB nodes before intersection
    delete headB->next->next;
    delete headB->next;
    delete headB;
    // free memory for common nodes
    delete inter->next;
    delete inter;

    return 0;
}
