//the sum of elements after being divided by the divisor should be less than equal to the threshold
#include <bits/stdc++.h>
using namespace std;

int sumbyD(vector<int> &nums, int div) {

    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        sum = sum + ceil((double)(nums[i]) / (double)(div));
    }

    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {

    int n = nums.size();

    if (n > threshold) {
        return -1;
    }

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high) {

        int mid = (low + high) / 2;

        if (sumbyD(nums, mid) <= threshold) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int threshold;

    cout << "Enter threshold: ";
    cin >> threshold;

    int result = smallestDivisor(nums, threshold);

    cout << "Smallest divisor: " << result << endl;

    return 0;
}