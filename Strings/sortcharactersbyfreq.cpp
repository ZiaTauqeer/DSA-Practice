#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        vector<vector<char>> bucket(s.size() + 1);

        // No structured binding, works with older C++
        for (auto& pair : freq) {
            bucket[pair.second].push_back(pair.first);
        }

        string result = "";

        for (int i = s.size(); i >= 1; i--) {

            for (char ch : bucket[i]) {
                result += string(i, ch);
            }
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s = "tree";

    string result = obj.frequencySort(s);

    cout << "Input: " << s << endl;
    cout << "Output: " << result << endl;

    return 0;
}