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

    // Create answer array of the same size
    vector<int> ans(n, 0);

    // Positive numbers will go at even indices:
    // 0, 2, 4, 6...
    int posIndex = 0;

    // Negative numbers will go at odd indices:
    // 1, 3, 5, 7...
    int negIndex = 1;

    for (int i = 0; i < n; i++) {

        // If the number is negative,
        // put it at the next odd position
        if (nums[i] < 0) {

            ans[negIndex] = nums[i];

            negIndex += 2;
        }

        // If the number is positive,
        // put it at the next even position
        else {

            ans[posIndex] = nums[i];

            posIndex += 2;
        }
    }

    // Print the rearranged array
    cout << "Rearranged array: ";

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}