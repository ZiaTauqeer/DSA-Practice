#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to floor and ceiling of x in arr[] 
vector<int> getFloorAndCeil(int x, vector<int> arr) {
    int n = arr.size();
    int floorDiff = INT_MAX, ceilDiff = INT_MAX;
    int ceilVal = -1, floorVal = -1;

    // Looping through the array to find the floor and ceil of x
    for (int i = 0; i < n; i++) {
        
        // Updating the ceil if the current element is 
        // greater than or equal to x and the difference
        // is smaller
        if (arr[i] >= x && ceilDiff > (arr[i] - x)) {
            ceilDiff = arr[i] - x;
            ceilVal = arr[i];
        }
        
        // Updating the floor if the current element is 
        // smaller than or equal to x and the difference
        // is smaller
        if (arr[i] <= x && floorDiff > (x - arr[i])) {
            floorDiff = x - arr[i];
            floorVal = arr[i];
        }
    }

    return {floorVal, ceilVal};
}

int main() {
    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    int x = 7;
    vector<int> ans = getFloorAndCeil(x, arr); 
    int floor_of_x = ans[0];
    int ceil_of_x = ans[1];
    
    cout << floor_of_x << " " << ceil_of_x << "\n";
    
    return 0;
}