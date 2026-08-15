#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[low];

    int i = low;// i is starting at a number lower than pivot
    int j = high;// j is starting at a number higher than pivot

    while (i < j) {
        // i moves from left to right and stops at a higher number than pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;//i moves forward
        }
        // j moves from right to left and stops at the number lesser than pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        // if i found a number more than pivot and j found a number lesser than pivot
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Put pivot in its correct position
    swap(arr[low], arr[j]);

    return j;
}


void qs(vector<int> &arr, int low, int high) {
// if array is sorted once
    if (low < high) {

        int pIndex = partition(arr, low, high);

        qs(arr, low, pIndex - 1);//sort left array created

        qs(arr, pIndex + 1, high);//sort right array created
    
    }
}
vector<int> quicksort(vector<int> arr) {

    qs(arr, 0, arr.size() - 1);

    return arr;
}


int main() {

    // Take size of array
    int n;

    cout << "Enter number of elements: ";
    cin >> n;


    // Create array
    vector<int> arr(n);


    // Take array input
    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr = quicksort(arr);


    // Print sorted array
    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}