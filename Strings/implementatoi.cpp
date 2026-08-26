#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // Remove leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {

            if (s[i] == '-')
                sign = -1;

            i++;
        }

        long long result = 0;

        // Read digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {

            result = result * 10 + (s[i] - '0');

            // Check overflow
            if (result * sign > INT_MAX)
                return INT_MAX;

            if (result * sign < INT_MIN)
                return INT_MIN;

            i++;
        }

        return result * sign;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.myAtoi(s);

    cout << "Integer value: " << result << endl;

    return 0;
}