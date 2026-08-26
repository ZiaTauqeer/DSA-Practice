#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        string r = "";

        vector<pair<int, string>> Roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100,"C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        for (int i = 0; i < Roman.size(); i++) {

            while (num >= Roman[i].first) {

                r += Roman[i].second;
                num -= Roman[i].first;
            }
        }

        return r;
    }
};

int main() {

    Solution obj;

    int num;

    cout << "Enter an integer: ";
    cin >> num;

    string result = obj.intToRoman(num);

    cout << "Roman numeral: " << result << endl;

    return 0;
}