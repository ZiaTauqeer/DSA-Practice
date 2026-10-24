
#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        // Base case: empty tree has depth 0
        if (root == nullptr) {
            return 0;
        }

        // Find depth of left subtree
        int maxLeft = maxDepth(root->left);

        // Find depth of right subtree
        int maxRight = maxDepth(root->right);

        // Return the greater depth + 1 for current node
        return max(maxLeft, maxRight) + 1;
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

    cout << "Maximum Depth: " << obj.maxDepth(root) << endl;

    return 0;
}
