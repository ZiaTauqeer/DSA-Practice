#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length())
            return false;

        int a[26] = {0};

        // Count characters in both strings
        for (int i = 0; i < s.length(); i++) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }

        // Check if all frequencies are zero
        for (int i = 0; i < 26; i++) {
            if (a[i] != 0)
                return false;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    bool result = obj.isAnagram(s, t);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}