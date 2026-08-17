#include <bits/stdc++.h>
using namespace std;

int main() {

    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> ans;

    for (int row = 1; row <= numRows; row++) {

        long long val = 1;

        vector<int> ansRow;

        // First element of every row is 1
        ansRow.push_back(1);

        for (int col = 1; col < row; col++) {

            // Calculate the next element
            val = val * (row - col);
            val = val / col;

            ansRow.push_back(val);
        }

        ans.push_back(ansRow);
    }

    cout << "Pascal's Triangle:" << endl;

    for (int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}