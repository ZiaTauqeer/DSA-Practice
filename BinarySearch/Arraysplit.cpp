#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        long long subarraySum = 0;

        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            }
            else {
                partitions++;
                subarraySum = num;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int answer = sol.splitArray(nums, k);

    cout << "Minimum largest subarray sum = " << answer << endl;

    return 0;
}