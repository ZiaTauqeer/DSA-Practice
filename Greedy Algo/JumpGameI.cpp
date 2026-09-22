#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
       Returns true if the last index can be reached
       from the first index using greedy reach tracking.
    */
    bool canJump(vector<int>& nums) {
        /*
           farthest stores the maximum index that can be
           reached using the jumps seen so far.
        */
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            /*
               If the current index is beyond farthest,
               this position cannot be reached.
            */
            if (i > farthest) {
                return false;
            }

            /*
               From a reachable index, try to extend the
               farthest reachable position.
            */
            farthest = max(farthest, i + nums[i]);

            /*
               If the reachable range already covers the
               last index, the answer is confirmed.
            */
            if (farthest >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};

// Driver code starts
int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << (solution.canJump(nums) ? "true" : "false") << endl;

    return 0;
}