#include <bits/stdc++.h>
using namespace std;

double shortestJobFirst(vector<int>& jobs) {
    int n = jobs.size();

    // Sort jobs by burst time
    sort(jobs.begin(), jobs.end());

    int waitingTime = 0;
    int totalWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime;

        // Current job's burst time
        waitingTime += jobs[i];
    }

    return (double)totalWaitingTime / n;
}

int main() {
    int n;
    cin >> n;

    vector<int> jobs(n);

    for (int i = 0; i < n; i++) {
        cin >> jobs[i];
    }

    double averageWaitingTime = shortestJobFirst(jobs);

    cout << "Average Waiting Time = " << averageWaitingTime << endl;

    return 0;
}