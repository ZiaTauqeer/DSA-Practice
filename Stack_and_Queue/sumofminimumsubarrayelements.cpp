#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        long long ans = 0;
        const long long MOD = 1000000007;

        stack<int> st;

        for (int i = 0; i <= n; i++) {

            int curr = (i == n) ? 0 : arr[i];

            while (!st.empty() && arr[st.top()] > curr) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                ans = (ans + (long long)arr[mid] * left * right) % MOD;
            }

            // Don't push the sentinel index n
            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> arr = {3, 1, 2, 4};

    cout << sol.sumSubarrayMins(arr) << endl;

    return 0;
}