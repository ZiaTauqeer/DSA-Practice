#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {

    int xorr = 0;

    for (int i = 0; i < nums.size(); i++) {
        xorr = xorr ^ nums[i];
    }

    return xorr;
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements." << endl;
    cout << "Each number should appear either once or twice, "
         << "and only one number should appear once:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int answer = singleNumber(nums);

    cout << "The number that appears only once is: " << answer << endl;

    return 0;
}