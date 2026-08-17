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

    int index = -1;

    // Find the first element from the right
    // which is smaller than the element after it.
    for (int i = n - 2; i >= 0; i--) {

        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // If index is -1, the array is in descending order.
    // Reverse the entire array to get the smallest permutation.
    if (index == -1) {
        reverse(nums.begin(), nums.end());
    }
    else {

        // Find the first element from the right
        // which is greater than nums[index].
        for (int i = n - 1; i > index; i--) {

            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Reverse everything after index
        // to get the smallest possible arrangement.
        reverse(nums.begin() + index + 1, nums.end());
    }

    cout << "Next permutation: ";

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}