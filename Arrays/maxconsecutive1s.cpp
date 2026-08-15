#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {

    int max1 = 0;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] == 1) {
            cnt++;

            // Keep track of the maximum consecutive 1s
            max1 = max(max1, cnt);
        }
        else {
            // Consecutive count breaks when we find 0
            cnt = 0;
        }
    }

    return max1;
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

    int answer = findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive 1s: " << answer << endl;

    return 0;
}