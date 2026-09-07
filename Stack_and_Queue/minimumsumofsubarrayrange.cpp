#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        // 'res' stores the final answer.
        // We use long long because the answer can become very large.
        long long res = 0;

        int n = nums.size();

        // j = index of the element we are processing
        // k = index of the previous smaller/greater element
        int j, k;

        // Stack stores indexes, not values.
        // We need indexes because they help us calculate
        // how many subarrays an element belongs to.
        stack<int> s;


        // =========================================================
        // PART 1: FIND CONTRIBUTION OF EACH ELEMENT AS A MINIMUM
        // =========================================================

        for (int i = 0; i <= n; ++i) {

            // We pop an element when we find a smaller element.
            //
            // This means nums[s.top()] can no longer be the minimum
            // for subarrays extending to the current position.
            //
            // When i == n, we use a very small value (-2e9)
            // to force all remaining elements out of the stack.
            while (!s.empty() &&
                   nums[s.top()] >
                   (i == n ? -2000000000 : nums[i])) {

                // j is the index of the element being removed.
                j = s.top();
                s.pop();

                // k is the index of the previous smaller element.
                //
                // If the stack is empty, there is no smaller element
                // on the left, so we use -1.
                k = s.empty() ? -1 : s.top();

                // Number of choices on the RIGHT:
                //
                // Current index i is the first smaller element
                // on the right.
                //
                // So we can choose the subarray's right boundary
                // from j up to i-1.
                //
                // Number of choices = i - j
                //
                // Number of choices on the LEFT:
                //
                // k is the previous smaller element.
                //
                // We can choose the left boundary from k+1 to j.
                //
                // Number of choices = j - k
                //
                // Therefore:
                //
                // contribution =
                // nums[j] * (number of right choices)
                //          * (number of left choices)
                //
                // We SUBTRACT minimum contributions because
                // we ultimately want:
                //
                // sum of maximums - sum of minimums
                res -= (long long)nums[j] *
                       (i - j) *
                       (j - k);
            }

            // We only push valid indexes.
            //
            // When i == n, i is outside the array, so pushing it
            // would later cause nums[n] -> out of bounds.
            if (i < n) {
                s.push(i);
            }
        }


        // Clear the stack before calculating maximum contributions.
        s = stack<int>();


        // =========================================================
        // PART 2: FIND CONTRIBUTION OF EACH ELEMENT AS A MAXIMUM
        // =========================================================

        for (int i = 0; i <= n; ++i) {

            // We pop an element when we find a GREATER element.
            //
            // This means nums[s.top()] can no longer be the maximum
            // for subarrays extending to the current position.
            //
            // When i == n, we use a very large value (2e9)
            // to force all remaining elements out of the stack.
            while (!s.empty() &&
                   nums[s.top()] <
                   (i == n ? 2000000000 : nums[i])) {

                // j is the index of the element being removed.
                j = s.top();
                s.pop();

                // k is the previous greater element.
                //
                // If there is no previous greater element,
                // we use -1.
                k = s.empty() ? -1 : s.top();

                // Number of choices on the RIGHT = i - j
                //
                // Number of choices on the LEFT = j - k
                //
                // Therefore this element is the maximum in:
                //
                // (i - j) * (j - k)
                //
                // subarrays.
                //
                // We ADD maximum contributions because the formula is:
                //
                //     Sum of ranges
                //   = Sum of maximums - Sum of minimums
                res += (long long)nums[j] *
                       (i - j) *
                       (j - k);
            }

            // Again, don't push i == n because it is outside
            // the array.
            if (i < n) {
                s.push(i);
            }
        }


        // Return:
        //
        // Total contribution of maximums
        // -
        // Total contribution of minimums
        //
        // This gives the sum of ranges of all subarrays.
        return res;
    }
};


int main() {

    // Create an object of Solution.
    Solution sol;

    // Test array.
    vector<int> nums = {1, 2, 3};

    // Call the function and print the answer.
    cout << sol.subArrayRanges(nums) << endl;

    return 0;
}