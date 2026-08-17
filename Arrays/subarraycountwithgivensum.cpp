#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the required sum k: ";
    cin >> k;

    map<int, int> mpp;

    // Prefix sum 0 has occurred once
    mpp[0] = 1;

    int preSum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {

        // Add current element to prefix sum
        preSum += arr[i];

        // Find the prefix sum that we need
        int remove = preSum - k;

        // If it exists, add its frequency to count
        cnt += mpp[remove];

        // Store/update the current prefix sum
        mpp[preSum]++;
    }

    cout << "Number of subarrays with sum " << k
         << " is: " << cnt << endl;

    return 0;
}