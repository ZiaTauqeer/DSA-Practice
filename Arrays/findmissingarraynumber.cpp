#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {

    int n = nums.size();

    // Sum of numbers from 0 to n
    int sum = (n * (n + 1)) / 2;

    // Sum of elements actually present in the array
    int s2 = 0;

    for (int i = 0; i < n; i++) {
        s2 += nums[i];
    }

    // Difference is the missing number
    return sum - s2;
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
    cout << "The missing number is: " << missingNumber(nums) << endl;

    return 0;
}