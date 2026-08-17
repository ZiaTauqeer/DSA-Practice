#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;

    int maxi = INT_MIN;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // If current element is greater than
        // all elements to its right, it is a leader
        if (a[i] > maxi) {
            ans.push_back(a[i]);
        }

        // Keep track of the maximum element
        // seen so far from the right
        maxi = max(maxi, a[i]);
    }

    // Leaders were found from right to left,
    // so reverse them to get their original order
    reverse(ans.begin(), ans.end());

    cout << "Leaders in the array are: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}