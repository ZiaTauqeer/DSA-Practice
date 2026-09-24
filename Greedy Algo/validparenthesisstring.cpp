#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {

    int leftMin = 0;
    int leftMax = 0;

    for (char c : s) {

        // '(' must be treated as an opening bracket
        if (c == '(') {
            leftMin++;
            leftMax++;
        }

        // ')' must be treated as a closing bracket
        else if (c == ')') {
            leftMin--;
            leftMax--;
        }

        // '*' can be '(', ')' or empty
        else {
            leftMin--;
            leftMax++;
        }

        // Even the maximum possible number of '('
        // has gone negative, so it is impossible
        if (leftMax < 0) {
            return false;
        }

        // Minimum cannot go below 0
        leftMin = max(leftMin, 0);
    }

    // If minimum possible unmatched '(' is 0,
    // we can make the string valid
    return leftMin == 0;
}

int main() {

    string s;
    cin >> s;

    if (checkValidString(s)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}