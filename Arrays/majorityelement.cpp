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

    int el;
    int cnt = 0;

    // First step: Find a possible majority element
    for (int i = 0; i < n; i++) {

        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        }

        else if (nums[i] == el) {
            cnt++;
        }

        else {
            cnt--;
        }
    }

    // Second step: Count how many times
    // the possible majority element actually appears
    int cnt1 = 0;

    for (int i = 0; i < n; i++) {

        if (nums[i] == el) {
            cnt1++;
        }
    }

    // Check whether it appears more than n/2 times
    if (cnt1 > n / 2) {
        cout << "The majority element is: " << el << endl;
    }
    else {
        cout << "There is no majority element." << endl;
    }

    return 0;
}