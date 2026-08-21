#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        long long low = 1;
        long long high = n;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    cout << obj.floorSqrt(n) << endl;

    return 0;
}