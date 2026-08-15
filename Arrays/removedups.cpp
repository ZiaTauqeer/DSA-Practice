#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {// i is previous unique element and j is like a scanner so if i==j that means a duplicate is found
            arr[i + 1] = arr[j];//set new unique element to the position of j
            i++;//move i forward bcz we found new unique element
        }
    }

    return i + 1;//tells the current number of unique elements
}

int main() {
    int arr[] = {1, 2, 3, 3, 4, 5, 6};
    int n = 7;
    int newSize = removeDuplicates(arr, n);//new size of array after removing dups. calls the remove duplicates function
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";//prints new array
    }
    return 0;
}