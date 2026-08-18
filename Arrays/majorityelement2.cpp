#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int cnt1 = 0;
    int cnt2 = 0;

    int el1 = INT_MIN;
    int el2 = INT_MIN;

    // Step 1: Find the two possible candidates
    for (int i = 0; i < n; i++) {

        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) {
            cnt1++;
        }
        else if (v[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Step 2: Verify the candidates
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {

        if (v[i] == el1)
            cnt1++;

        if (v[i] == el2)
            cnt2++;
    }

    int mini = n / 3;

    cout << "Majority elements are: ";

    if (cnt1 > mini) {
        cout << el1 << " ";
    }

    if (cnt2 > mini && el2 != el1) {
        cout << el2 << " ";
    }

    cout << endl;

    return 0;
}