#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        // Base case
        if (root == nullptr) {
            return;
        }

        // Root -> Left -> Right
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

int main() {
    // Creating the binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    vector<int> result = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}