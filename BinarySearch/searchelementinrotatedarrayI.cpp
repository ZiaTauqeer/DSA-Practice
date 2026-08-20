#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // Target found
        if (nums[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid]) {

            // Target lies in the sorted left half
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {

            // Target lies in the sorted right half
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}


int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    int result = search(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    }
    else {
        cout << "Target not found." << endl;
    }

    return 0;
}