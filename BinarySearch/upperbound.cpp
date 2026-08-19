#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int target) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] > target) {//only difference between lower and upper bound is that lower bound has '=' 
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    int result = lowerBound(arr, target);

    if (result == n) {
        cout << "No element greater than or equal to " << target << " exists." << endl;
    }
    else {
        cout << "Lower bound of " << target << " is at index: "
             << result << endl;

        cout << "Element at lower bound: " << arr[result] << endl;
    }

    return 0;
}