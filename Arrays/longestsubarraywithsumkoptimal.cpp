//using 2 pointer approach
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0;
    int right = 0;

    long long sum = a[0];

    int maxLen = 0;

    int n = a.size();

    while (right < n) {
        // If sum is greater than k,
        // remove elements from the left
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        // If current window has sum k,
        // calculate its length
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move right pointer forward
        right++;

        // Add the new element to the sum
        if (right < n) {
            sum += a[right];
        }
    }

    return maxLen;
}
int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long k;

    cout << "Enter the required sum (k): ";
    cin >> k;

    int answer = longestSubarrayWithSumK(a, k);

    cout << "Length of longest subarray with sum "
         << k << " is: " << answer << endl;

    return 0;
}