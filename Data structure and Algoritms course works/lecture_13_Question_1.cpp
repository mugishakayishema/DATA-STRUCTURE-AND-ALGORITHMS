//reg number: 224003729
//Names: Mugisha Kayishema 

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Level-order print to show structure (prints nulls for clarity)
void printLevelOrder(Node* root) {
    if (!root) {
        cout << "(empty)\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    bool anyNonNull = true;
    while (anyNonNull) {
        int sz = (int)q.size();
        anyNonNull = false;
        for (int i = 0; i < sz; ++i) {
            Node* n = q.front(); q.pop();
            if (n) {
                cout << setw(3) << n->val;
                q.push(n->left);
                q.push(n->right);
                if (n->left || n->right) anyNonNull = true;
            }
            else {
                cout << setw(3) << "N";
                q.push(nullptr);
                q.push(nullptr);
            }
        }
        cout << '\n';
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    root->right->left->right=new Node(10);
    root->right->left->left=new Node(11);
    root->right->right->left=new Node(12);
    root->right->right->right=new Node(13);

    cout << "Original tree (level-order):\n";
    printLevelOrder(root);

    mirror(root);

    cout << "\nMirrored tree (level-order):\n";
    printLevelOrder(root);

    deleteTree(root);
    return 0;
}
