
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base case: if either node is NULL
        if (p == nullptr || q == nullptr) {
            return (p == q);
        }

        // Check values and recursively compare left and right subtrees
        return (p->val == q->val)
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

int main() {

    // First tree
    //       1
    //      / \
    //     2   3

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Second tree
    //       1
    //      / \
    //     2   3

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q)) {
        cout << "Both trees are identical" << endl;
    }
    else {
        cout << "Trees are not identical" << endl;
    }

    return 0;
}
