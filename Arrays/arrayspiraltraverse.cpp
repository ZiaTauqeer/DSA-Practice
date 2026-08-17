#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int left = 0;
    int right = m - 1;
    int top = 0;
    int bottom = n - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {

        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }

        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }

        right--;

        // Traverse from right to left
        if (top <= bottom) {

            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {

            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }

            left++;
        }
    }

    cout << "Spiral order: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}