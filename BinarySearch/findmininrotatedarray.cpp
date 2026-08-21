#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (nums[low] <= nums[mid]) {

            ans = min(ans, nums[low]);
            low = mid + 1;

        }
        else {

            high = mid - 1;
            ans = min(ans, nums[mid]);
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter size of rotated sorted array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = findMin(nums);

    cout << "Minimum element is: " << result << endl;

    return 0;
}