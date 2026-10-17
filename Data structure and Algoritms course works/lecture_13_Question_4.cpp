// Reg number: 224003729
//Names:Mugisha kayishema 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize tree to string (pre-order)
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Deserialize using vector + index (safer than queue.front on empty)
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;
        vector<string> nodes;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        int pos = 0;
        return deserializeHelper(nodes, pos);
    }

private:
    TreeNode* deserializeHelper(const vector<string>& nodes, int& pos) {
        if (pos >= static_cast<int>(nodes.size())) return nullptr;
        const string& val = nodes[pos++];
        if (val == "#") return nullptr;
        // stoi may throw if input is invalid; for trusted input this is fine
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes, pos);
        node->right = deserializeHelper(nodes, pos);
        return node;
    }
};

// Helper to free tree memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    TreeNode* newRoot = codec.deserialize(serialized);
    if (newRoot) {
        cout << "Deserialized Root Value: " << newRoot->val << endl; // Should print 1
    } else {
        cout << "Deserialization returned null." << endl;
    }

    // Free memory
    deleteTree(root);
    deleteTree(newRoot);

    return 0;
}
