#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Finds the minimum platforms by checking
    every arrival time as a possible busy moment.
    */
    int minimumPlatforms(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        // This stores the maximum number of trains
        // present together at any checked arrival time.
        int minimumPlatforms = 0;

        for (int i = 0; i < n; i++) {
            // This stores how many trains are present
            // at the current train's arrival time.
            int trainsPresent = 0;

            for (int j = 0; j < n; j++) {
                // A train is present if it has already arrived
                // and has not departed before this moment.
                if (arr[j] <= arr[i] && dep[j] >= arr[i]) {
                    trainsPresent++;
                }
            }

            // The answer must cover the busiest moment seen so far.
            minimumPlatforms = max(minimumPlatforms, trainsPresent);
        }

        return minimumPlatforms;
    }
};

// Driver code starts
int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    Solution sol;
    cout << sol.minimumPlatforms(arr, dep) << endl;

    return 0;
}