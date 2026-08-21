#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low < high) {

        int mid = (low + high) / 2;

        // Make mid even
        if (mid % 2 == 1) {
            mid--;
        }

        // Pair is correct
        if (nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        }
        else {
            high = mid;
        }
    }

    return nums[low];
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNonDuplicate(nums);

    cout << "The single element is: " << result << endl;

    return 0;
}