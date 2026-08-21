#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>& piles) {
    int maxi = INT_MIN;
    int n = piles.size();

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }

    return maxi;
}

long long Hour(vector<int>& piles, int hourly) {

    long long totalhrs = 0; //keep it long long to clear all test cases.
    int n = piles.size();

    for (int i = 0; i < n; i++) {
        totalhrs += ceil((double)piles[i] / (double)hourly);
    }

    return totalhrs;
}

int minEatingSpeed(vector<int>& piles, int h) {

    int low = 1;
    int high = findMax(piles);

    while (low <= high) {

        int mid = (low + high) / 2;

        long long totalhrs = Hour(piles, mid);

        if (totalhrs <= h) {
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

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter piles: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;

    cout << "Enter number of hours: ";
    cin >> h;

    int result = minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}