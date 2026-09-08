#include <bits/stdc++.h>
using namespace std;

class StockSpanner {

    // Store:
    // first  -> stock price
    // second -> span of that price
    stack<pair<int, int>> st;

public:

    StockSpanner() {
        // Constructor
    }

    int next(int price) {

        // Every price has at least a span of 1
        // because the current day itself is included.
        int span = 1;

        // If the previous price is smaller than or equal
        // to the current price, it can be included in
        // the current span.
        while (!st.empty() && st.top().first <= price) {

            // Instead of counting that day one by one,
            // we add its already calculated span.
            span += st.top().second;

            // Remove it because the current price is
            // greater than or equal to it.
            st.pop();
        }

        // Store the current price along with its span.
        st.push({price, span});

        // Return the number of consecutive days
        // for which the price was <= current price.
        return span;
    }
};


int main() {

    StockSpanner stockSpanner;

    // Test case
    vector<int> prices = {
        100, 80, 60, 70, 60, 75, 85
    };

    for (int price : prices) {

        cout << "Price: " << price
             << "  Span: "
             << stockSpanner.next(price)
             << endl;
    }

    return 0;
}