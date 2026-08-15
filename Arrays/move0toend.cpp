#include <bits/stdc++.h>
using namespace std;

void moveZeroes(int n, int arr[]) {

    // j points to the position where the next
    // non-zero element should be placed.
    int j = 0;

    // i scans through every element of the array.
    for (int i = 0; i < n; i++) {

        // If we find a non-zero element...
        if (arr[i] != 0) {

            // Put this non-zero element at position j.
            swap(arr[i], arr[j]);

            // Move j forward because position j
            // is now occupied by a non-zero element.
            j++;
        }
    }
}

int main() {

    int n;
    cin >> n;

    // Create the array.
    int arr[n];

    // Take input.
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Move all zeroes to the end.
    moveZeroes(n, arr);

    // Print the resulting array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}