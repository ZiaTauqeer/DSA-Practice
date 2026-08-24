#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n = s.size();
        int m = t.size();

        if (n != m)
            return false;

        map<char, char> mp;
        set<char> usedchar;

        for (int i = 0; i < n; i++) {

            // Character already has a mapping
            if (mp.find(s[i]) != mp.end()) {

                if (mp[s[i]] != t[i])
                    return false;
            }

            // Character does not have a mapping yet
            else {

                // t[i] is already mapped to another character
                if (usedchar.find(t[i]) != usedchar.end())
                    return false;

                mp[s[i]] = t[i];
                usedchar.insert(t[i]);
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s = "egg";
    string t = "add";

    bool ans = obj.isIsomorphic(s, t);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}