#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k) {

    int xr = 0;
    long cnt = 0;
    int n = arr.size();

    map<int, int> mpp;

    mpp[xr]++;

    for (int i = 0; i < n; i++) {

        xr = xr ^ arr[i];

        int x = xr ^ k;

        cnt += mpp[x];

        mpp[xr]++;
    }

    return cnt;
}


int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;

    cout << "Enter target XOR (k): ";
    cin >> k;

    long result = subarrayXor(arr, k);

    cout << "Number of subarrays with XOR " << k << " is: "
         << result << endl;

    return 0;
}