#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {

            // Check if current digit is odd
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};

int main() {

    Solution obj;

    string num = "35427";

    string ans = obj.largestOddNumber(num);

    cout << "Input:  " << num << endl;
    cout << "Output: " << ans << endl;

    return 0;
}