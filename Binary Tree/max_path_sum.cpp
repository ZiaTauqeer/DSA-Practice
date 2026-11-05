
#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        maxPathDown(root, maxi);

        return maxi;
    }

    int maxPathDown(TreeNode* node, int& maxi) {

        // Base case
        if (node == nullptr) {
            return 0;
        }

        // Calculate left and right maximum path sums
        // Ignore negative paths
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        // Update maximum path sum
        maxi = max(maxi, left + right + node->val);

        // Return maximum one-sided path to parent
        return max(left, right) + node->val;
    }
};

int main() {

    // Creating the binary tree
    //        -10
    //        / \
    //       9   20
    //          /  \
    //         15   7

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root) << endl;

    return 0;
}
