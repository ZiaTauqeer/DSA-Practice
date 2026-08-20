//same as above but with duplicate elements
#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // Target found
        if (nums[mid] == target) {
            return true;
        }

        // Duplicates make it impossible to determine
        // which half is sorted
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        }

        // Left half is sorted
        else if (nums[low] <= nums[mid]) {

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

    return false;
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

    bool result = search(nums, target);

    if (result) {
        cout << "Target is present in the array." << endl;
    }
    else {
        cout << "Target is not present in the array." << endl;
    }

    return 0;
}