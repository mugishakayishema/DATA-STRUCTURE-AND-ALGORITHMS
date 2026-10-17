//reg number:224003729
//Names: Mugisha kayishema
#include <iostream>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;

    Node* p1 = headA;
    Node* p2 = headB;
    while (p1 != p2) {
        p1 = (p1 == nullptr) ? headB : p1->next;
        p2 = (p2 == nullptr) ? headA : p2->next;
    }

    return p1;
}

int main() {
    Node* common = new Node(6);
    common->next = new Node(7);

    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common;

    Node* headB = new Node(4);
    headB->next = new Node(5);
    headB->next->next = common;

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
