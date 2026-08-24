#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {

            if (ch == ')')
                st.pop();

            if (!st.empty())
                ans += ch;

            if (ch == '(')
                st.push(ch);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "(()())(())";

    string ans = obj.removeOuterParentheses(s);

    cout << "Input:  " << s << endl;
    cout << "Output: " << ans << endl;

    return 0;
}