//Reg number: 224003729
//Names: Mugisha kayishema
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    // Subtract current node value from target
    targetSum -= root->val;

    // If it's a leaf node, check if sum is zero
    if (root->left == nullptr && root->right == nullptr) {
        return (targetSum == 0);
    }

    // Recurse on left and right children
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum=26;

    if (hasPathSum(root, targetSum))
        cout << "Path with sum " << targetSum << " exists!" << endl;
    else
        cout << "No path with sum " << targetSum << " found." << endl;

    return 0;
}
