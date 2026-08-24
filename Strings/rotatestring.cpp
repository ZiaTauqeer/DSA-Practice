#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        // If lengths are different, rotation is impossible
        if (s.size() != goal.size())
            return false;

        // Concatenate s with itself
        s += s;

        int m = goal.size();
        int n = s.size();

        // Check if goal exists inside s+s
        for (int i = 0; i <= n - m; i++) {

            bool match = true;

            for (int j = 0; j < m; j++) {

                if (s[i + j] != goal[j]) {
                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }

        return false;
    }
};

int main() {

    Solution obj;

    string s = "abcde";
    string goal = "cdeab";

    bool result = obj.rotateString(s, goal);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}