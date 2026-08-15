#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {

    map<long long, int> preSumMap;

    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++) {

        sum += a[i];

        // If the prefix sum itself is k,
        // then the subarray from index 0 to i has sum k.
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;

        // Check if a previous prefix sum was equal to rem.
        if (preSumMap.find(rem) != preSumMap.end()) {

            int len = i - preSumMap[rem];

            maxLen = max(maxLen, len);
        }

        // Store the first occurrence of this prefix sum.
        // We only store it if it hasn't appeared before.
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
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

    cout << "Length of the longest subarray with sum " << k
         << " is: " << answer << endl;

    return 0;
}