#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices for each day: ";

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Keep track of the lowest price seen so far
    int mini = prices[0];

    int maxprofit = 0;

    for (int i = 1; i < n; i++) {

        // Profit if we buy at the lowest price
        // and sell today
        int cost = prices[i] - mini;

        // Keep the maximum profit found so far
        maxprofit = max(maxprofit, cost);

        // Update the minimum price
        mini = min(mini, prices[i]);
    }

    cout << "Maximum profit is: " << maxprofit << endl;

    return 0;
}