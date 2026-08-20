#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &nums, int target) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}


int upperbound(vector<int> &nums, int target) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}


vector<int> searchRange(vector<int>& nums, int target) {

    int n = nums.size();

    int lb = lowerbound(nums, target);

    if (lb == n || nums[lb] != target) {
        return {-1, -1};
    }

    return {lb, upperbound(nums, target) - 1};
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

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = searchRange(nums, target);

    cout << "First and last position of target: ";

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}