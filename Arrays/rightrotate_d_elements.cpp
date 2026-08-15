#include <bits/stdc++.h>
using namespace std;

void rightrotate(int n, int arr[], int d) {
    d = d % n;
    reverse(arr, arr + n);
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
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

    rightrotate(n, arr, d);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}