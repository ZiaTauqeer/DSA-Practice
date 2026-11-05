
#include <iostream>
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

    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both nodes are NULL
        if (!left && !right) {
            return true;
        }

        // Only one node is NULL
        if (!left || !right) {
            return false;
        }

        // Check values and compare opposite subtrees
        return (left->val == right->val)
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric
        if (!root) {
            return true;
        }

        return isMirror(root->left, root->right);
    }
};

int main() {

    // Creating a symmetric binary tree
    //
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root)) {
        cout << "Tree is Symmetric" << endl;
    }
    else {
        cout << "Tree is Not Symmetric" << endl;
    }

    return 0;
}
