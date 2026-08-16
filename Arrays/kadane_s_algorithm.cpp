#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int sum = 0;

    // Start with the first element so that
    // arrays containing only negative numbers also work.
    int maxi = nums[0];

    for (int i = 0; i < n; i++) {

        // Add current element to the current subarray sum
        sum += nums[i];

        // Update maximum sum if current sum is greater
        if (sum > maxi) {
            maxi = sum;
        }

        // If sum becomes negative, start a new subarray
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum subarray sum is: " << maxi << endl;

    return 0;
}