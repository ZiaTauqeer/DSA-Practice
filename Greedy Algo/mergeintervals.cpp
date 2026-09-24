#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    // Step 1: Sort intervals by starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    // Step 2: Go through every interval
    for (const auto& interval : intervals) {

        // If ans is not empty and current interval overlaps
        // with the last interval in ans
        if (!ans.empty() && interval[0] <= ans.back()[1]) {

            // Extend the ending time if necessary
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
        else {
            // No overlap, so add the interval separately
            ans.push_back(interval);
        }
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    // Input intervals
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Call merge function
    vector<vector<int>> result = merge(intervals);

    // Print result
    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}