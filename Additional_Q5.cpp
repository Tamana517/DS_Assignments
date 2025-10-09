/*
Q5: Given two polynomial numbers represented by two linked lists. The task is
to add these lists (meaning the coefficients with the same variable powers will be
added).
*/

// Time Complexity: O(m+n), Space Complexity: O(m+n) where m = number of terms of poly1 ,and n = number of terms of poly2

#include <iostream>
using namespace std;

struct Node {
    int coeff;  // coefficient
    int pow;    // power
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(NULL) {}
};

// insert at end using tail pointer (O(1))
void insertTail(Node*& head, Node*& tail, int c, int p) {
    Node* temp = new Node(c, p);
    if (!head)
        head = tail = temp;
    else {
        tail->next = temp;
        tail = temp;
    }
}

// add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node *head = NULL, *tail = NULL;

    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) insertTail(head, tail, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow) {
            insertTail(head, tail, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            insertTail(head, tail, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    // attach remaining terms
    while (p1) {
        insertTail(head, tail, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insertTail(head, tail, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return head;
}

// print polynomial
void printPoly(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next && head->next->coeff >= 0) cout << " + ";
        else if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *poly1 = NULL, *tail1 = NULL;
    Node *poly2 = NULL, *tail2 = NULL;
  
    //Example Usage:
    // poly1: 5x^2 + 4x^1 + 2
    insertTail(poly1, tail1, 5, 2);
    insertTail(poly1, tail1, 4, 1);
    insertTail(poly1, tail1, 2, 0);

    // poly2: 5x + 5
    insertTail(poly2, tail2, 5, 1);
    insertTail(poly2, tail2, 5, 0);

    cout << "1st Polynomial: ";
    printPoly(poly1);
    cout << "2nd Polynomial: ";
    printPoly(poly2);

    Node* sum = addPoly(poly1, poly2);
    cout << "Sum: ";
    printPoly(sum);

    return 0;
}
