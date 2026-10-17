//reg number:224003729
//Names: Mugisha kayishema
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;
    Node* temp = secondHalf;
    bool palindrome = true;

    while (temp != nullptr) {
        if (firstHalf->data != temp->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    slow->next = reverseList(secondHalf);

    return palindrome;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
	Node* head2 = new Node(1);
	head2->next = new Node(2);
	head2->next->next = new Node(4);
	head2->next->next->next = new Node(2);
    if (isPalindrome(head))
        cout << "Linked list is a palindrome" << endl;
    else
        cout << "Linked list is NOT a palindrome" << endl;

    if (isPalindrome(head2))
        cout << "Linked list is a palindrome" << endl;
    else
        cout << "Linked list is NOT a palindrome" << endl;

    return 0;
}
