#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    int n = s.size();
    int m = t.size();

    int l = 0, r = 0, cnt = 0;
    int minlen = 1e9;
    int sIndex = -1;

    int hash[256] = {0};

    // Store frequency of characters in t
    for (int i = 0; i < m; i++) {
        hash[t[i]]++;
    }

    // Sliding window
    while (r < n) {

        // Add s[r] to the window
        if (hash[s[r]] > 0) {
            cnt++;
        }

        hash[s[r]]--;

        // If window contains all characters of t
        while (cnt == m) {

            // Check if current window is smaller
            if (r - l + 1 < minlen) {
                minlen = r - l + 1;
                sIndex = l;
            }

            // Remove s[l] from window
            hash[s[l]]++;

            if (hash[s[l]] > 0) {
                cnt--;
            }

            l++;
        }

        r++;
    }

    // No valid window found
    if (sIndex == -1) {
        return "";
    }

    return s.substr(sIndex, minlen);
}

int main() {

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    string answer = minWindow(s, t);

    cout << "Minimum window: " << answer << endl;

    return 0;
}