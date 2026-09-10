#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // 'l' represents the left side of our window.
        int l = 0;

        // Stores the maximum length of a valid window.
        int maxLen = 0;

        // Stores:
        // fruit type -> number of fruits of that type
        //
        // We are allowed to have at most 2 different
        // types of fruits in our window.
        unordered_map<int, int> basket;

        // 'r' represents the right side of our window.
        for (int r = 0; r < fruits.size(); ++r) {

            // Add the current fruit to the basket.
            basket[fruits[r]]++;

            // If we now have more than 2 different
            // types of fruits, the window is invalid.
            //
            // Move the left pointer until we have
            // at most 2 different fruit types again.
            while (basket.size() > 2) {

                // Remove the fruit at the left side.
                basket[fruits[l]]--;

                // If there are no more fruits of this type,
                // remove the type completely from the map.
                if (basket[fruits[l]] == 0) {
                    basket.erase(fruits[l]);
                }

                // Move the left pointer forward.
                l++;
            }

            // Current window is:
            //
            // [l ........ r]
            //
            // Its length is:
            // r - l + 1
            //
            // Keep the maximum length found so far.
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};


int main() {

    Solution sol;

    // Test case
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 2};

    cout << "Maximum fruits: "
         << sol.totalFruit(fruits)
         << endl;

    return 0;
}