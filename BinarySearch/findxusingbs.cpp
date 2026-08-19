#include <bits/stdc++.h>
using namespace std;

int searchElement(vector<int>& nums, int target) {

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        else if (target > nums[mid]) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

    int n;

    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    int result = searchElement(nums, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    }
    else {
        cout << "Target not found." << endl;
    }

    return 0;
}