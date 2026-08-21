#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int>& arr) {

    int n = arr.size();
    int low = 0;
    int high = n - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // Array is already sorted
        if (arr[low] <= arr[high]) {

            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            break;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {

            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            low = mid + 1;
        }

        // Right half is sorted
        else {

            high = mid - 1;

            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
        }
    }

    return index;
}

int main() {

    int n;

    cout << "Enter size of rotated sorted array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findKRotation(arr);

    cout << "Number of rotations: " << result << endl;

    return 0;
}