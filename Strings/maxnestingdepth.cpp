#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {

        int ans = 0;
        int depth = 0;

        for (char ch : s) {

            if (ch == '(')
                depth++;

            else if (ch == ')')
                depth--;

            if (depth > ans)
                ans = depth;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = obj.maxDepth(s);

    cout << "Maximum Depth: " << result << endl;

    return 0;
}