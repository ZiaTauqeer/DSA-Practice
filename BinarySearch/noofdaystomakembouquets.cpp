#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {

    int cnt = 0;
    int noofB = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noofB += cnt / k;
            cnt = 0;
        }
    }

    noofB += cnt / k;

    return noofB >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {

    long long val = m * 1LL * k;

    // Impossible to make m bouquets
    if (val > bloomDay.size()) {
        return -1;
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < bloomDay.size(); i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    int low = mini;
    int high = maxi;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (possible(bloomDay, mid, m, k)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {

    int n;

    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> bloomDay(n);

    cout << "Enter bloom days: ";
    for (int i = 0; i < n; i++) {
        cin >> bloomDay[i];
    }

    int m, k;

    cout << "Enter number of bouquets: ";
    cin >> m;

    cout << "Enter flowers required per bouquet: ";
    cin >> k;

    int result = minDays(bloomDay, m, k);

    cout << "Minimum number of days: " << result << endl;

    return 0;
}