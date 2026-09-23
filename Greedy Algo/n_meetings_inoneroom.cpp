#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
       Finds the maximum number of meetings that can be
       scheduled in one room without overlapping.
    */
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        /*
           Each meeting is stored with its end time first so
           sorting naturally arranges meetings by finish time.
        */
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        sort(meetings.begin(), meetings.end());

        /*
           This stores the ending time of the last selected
           meeting. -1 allows the first valid meeting to fit.
        */
        int lastEndTime = -1;

        /*
           This stores how many meetings have been selected so far.
        */
        int count = 0;

        for (auto meeting : meetings) {
            int currentEnd = meeting.first;
            int currentStart = meeting.second;

            /*
               A meeting can be selected only when it starts
               strictly after the previously selected meeting ends.
            */
            if (currentStart > lastEndTime) {
                count++;
                lastEndTime = currentEnd;
            }
        }

        return count;
    }
};

int main() {
    // Driver code starts
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution sol;
    cout << sol.maxMeetings(start, end);

    return 0;
}