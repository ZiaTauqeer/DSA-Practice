#include <bits/stdc++.h>
using namespace std;

void leftrotate(int n, int arr[], int d) {

    // If d is greater than n, reduce it
    // because rotating n times gives the original array.
    d = d % n;

    // Step 1:
    // Reverse the FIRST d elements.
    //
    // Example:
    // arr = [1 2 3 4 5]
    // d = 2
    //
    // First d elements = [1 2]
    // After reverse     = [2 1]
    //
    // Array becomes:
    // [2 1 3 4 5]
    reverse(arr, arr + d);


    // Step 2:
    // Reverse the elements from index d to n-1.
    //
    // [2 1 | 3 4 5]
    //        ^^^^^^^
    //        reverse this part
    //
    // [2 1 | 5 4 3]
    reverse(arr + d, arr + n);


    // Step 3:
    // Reverse the ENTIRE array.
    //
    // [2 1 5 4 3]
    //      ↓ reverse everything
    //
    // [3 4 5 1 2]
    //
    // This is the array rotated left by 2 positions.
    reverse(arr, arr + n);
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cout << "Enter rotation amount: ";
    cin >> d;

    leftrotate(n, arr, d);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}