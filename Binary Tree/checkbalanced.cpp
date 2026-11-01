
#include <iostream>
#include <algorithm>
#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root) {

        // Base case
        if (root == nullptr) {
            return 0;
        }

        // Calculate left subtree height
        int leftHeight = dfsHeight(root->left);

        if (leftHeight == -1) {
            return -1;
        }

        // Calculate right subtree height
        int rightHeight = dfsHeight(root->right);

        if (rightHeight == -1) {
            return -1;
        }

        // Check height difference
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {

    // Creating a balanced binary tree
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

    if (obj.isBalanced(root)) {
        cout << "Tree is Balanced" << endl;
    }
    else {
        cout << "Tree is Not Balanced" << endl;
    }

    return 0;
}
