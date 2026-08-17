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

    if (n == 0) {
        cout << "Longest consecutive sequence length is: 0" << endl;
        return 0;
    }

    int longest = 1;

    unordered_set<int> st;

    // Put all elements into the set
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    // Check every unique element
    for (auto it : st) {

        // If it-1 does not exist, this is the
        // starting point of a consecutive sequence
        if (st.find(it - 1) == st.end()) {

            int cnt = 1;
            int x = it;

            // Keep checking for the next consecutive number
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }

            longest = max(longest, cnt);
        }
    }

    cout << "Longest consecutive sequence length is: "
         << longest << endl;

    return 0;
}