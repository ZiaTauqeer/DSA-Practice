#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        string ans = "";

        for (int i = 0; i < first.size(); i++) {

            if (first[i] != last[i])
                break;

            ans += first[i];
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };

    string ans = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << ans << endl;

    return 0;
}