// Reg number: 224003729
//Names:Mugisha Kayishema 
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> stk;

    // Helper to push all left children
    void pushLeft(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Return true if there are more nodes
    bool hasNext() {
        return !stk.empty();
    }

    // Return next smallest value
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        // Push left children of right subtree
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
};

int main() {


    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    return 0;
}
