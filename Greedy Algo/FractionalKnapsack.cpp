#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    for (int i = 0; i < items.size(); i++) {

        // If the entire item can fit
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        }

        // If only a fraction can fit
        else {
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    double answer = fractionalKnapsack(W, items);

    cout << "Maximum value: " << answer << endl;

    return 0;
}