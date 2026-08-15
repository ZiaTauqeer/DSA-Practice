#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {

    // Base case:
    // If only one element is left,
    // the array is already sorted.
    if (n == 1) {
        return;
    }
    int didSwap = 0;
    // One complete bubble-sort pass
    // This pushes the largest element to the end.
    for (int j = 0; j < n - 1; j++) {

        if (arr[j] > arr[j + 1]) {

            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;

            didSwap = 1;
        }
    }

    // If no swapping happened,
    // array is already sorted.
    if (didSwap == 0) {
        return;
    }

    // Recursive call:
    // Sort the remaining n-1 elements.
    bubble_sort(arr, n - 1);
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

    bubble_sort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}