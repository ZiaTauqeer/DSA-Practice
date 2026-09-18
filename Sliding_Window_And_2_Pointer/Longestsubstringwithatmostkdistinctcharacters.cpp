#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find longest substring with at most K distinct characters
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // Edge case: if k is 0 or string is empty
        if (k == 0 || s.empty()) return 0;

        // Hash map to store frequency of characters in current window
        unordered_map<char, int> freq;

        // Initialize left pointer of sliding window
        int left = 0;

        // Initialize variable to store maximum length
        int maxLen = 0;

        // Loop through the string using right pointer
        for (int right = 0; right < s.length(); right++) {
            // Include current character into frequency map
            freq[s[right]]++;

            // Shrink window if number of distinct characters exceeds k
            while (freq.size() > k) {
                freq[s[left]]--;

                // If character count becomes zero, erase from map
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                // Move left pointer ahead
                left++;
            }

            // Update maxLen with current valid window size
            maxLen = max(maxLen, right - left + 1);
        }

        // Return the final answer
        return maxLen;
    }
};

// Driver code
int main() {
    Solution sol;
    string s = "eceba";
    int k = 2;
    cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}
