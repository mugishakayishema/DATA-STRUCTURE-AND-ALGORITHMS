//reg number:224003729
//Names: Mugisha kayishema
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* rotateList(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    Node* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    tail->next = head;
    k = k % length;
    int stepsToNewHead = length - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = rotateList(head, k);

    cout << "List after rotating by " << k << " positions: ";
    printList(head);

    return 0;
}
