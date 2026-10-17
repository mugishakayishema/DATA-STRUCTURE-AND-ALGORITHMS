//reg number:224003729
//Names: Mugisha kayishema
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node dummy(0);
    Node* curr = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    return dummy.next;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    cout << "List1: ";
    printList(l1);
    cout << "List2: ";
    printList(l2);

    Node* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
