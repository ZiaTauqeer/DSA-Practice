#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {

    // Base case:
    // If there is only one element,
    // it is already sorted.
    if (n <= 1) {
        return;
    }

    // First recursively sort the first n-1 elements.
    insertion_sort(arr, n - 1);

    // Now insert the nth element
    // into its correct position.
    int j = n - 1;

    while (j > 0 && arr[j - 1] > arr[j]) {

        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;

        j--;
    }
}


int main() {

    int n;

    cout << "Enter number of values in array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter element value: ";
        cin >> arr[i];
    }

    insertion_sort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}