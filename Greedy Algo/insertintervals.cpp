// C++ program to insert interval using single pass optimal approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Phase 1: Add all intervals completely before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Phase 2: Merge all overlapping intervals into one massive interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the fully merged new interval
        result.push_back(newInterval);
        
        // Phase 3: Add all remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    
    cout << "Merged Intervals: ";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
    }
    cout << endl;
    return 0;
}