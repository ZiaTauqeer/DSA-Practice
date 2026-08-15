#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter array element ";
        cin >> arr[i];
    }

    bool sorted = true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is unsorted" << endl;
    }
}