#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    map<int, int> mpp;

    int n = nums.size();

    for (int i = 0; i < n; i++) {

        int num = nums[i];

        // Find the number we need to reach target
        int moreNeeded = target - num;

        // Check if that number was already seen
        if (mpp.find(moreNeeded) != mpp.end()) {

            // Return the index of the previous number
            // and the current index
            return {mpp[moreNeeded], i};
        }

        // Store number and its index
        mpp[num] = i;
    }

    // If no pair is found
    return {-1, -1};
}


int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (result[0] == -1) {
        cout << "No pair found." << endl;
    }
    else {
        cout << "The indices are: "
             << result[0] << " " << result[1] << endl;

        cout << "The numbers are: "
             << nums[result[0]] << " "
             << nums[result[1]] << endl;
    }

    return 0;
}