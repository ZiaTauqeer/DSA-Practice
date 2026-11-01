
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        diameter(root, res);

        return res;
    }

private:
    int diameter(TreeNode* curr, int& res) {

        // Base case
        if (curr == nullptr) {
            return 0;
        }

        // Calculate left subtree height
        int left = diameter(curr->left, res);

        // Calculate right subtree height
        int right = diameter(curr->right, res);

        // Update maximum diameter
        res = max(res, left + right);

        // Return height of current node
        return max(left, right) + 1;
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

    cout << "Diameter of Binary Tree: "
         << obj.diameterOfBinaryTree(root) << endl;

    return 0;
}
