#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {

            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i == n)
                break;

            string word = "";

            // Get the word
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }

            // Reverse individual word
            reverse(word.begin(), word.end());

            // Add space between words
            if (ans.size() > 0)
                ans += " " + word;
            else
                ans += word;
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "the sky is blue";

    string ans = obj.reverseWords(s);

    cout << "Input:  " << s << endl;
    cout << "Output: " << ans << endl;

    return 0;
}