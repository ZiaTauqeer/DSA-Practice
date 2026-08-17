#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 1: Transpose the matrix
    for (int i = 0; i < n - 1; i++) {

        for (int j = i; j < n; j++) {

            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse every row
    for (int i = 0; i < n; i++) {

        reverse(matrix[i].begin(), matrix[i].end());
    }

    // Print the rotated matrix
    cout << "Matrix after 90 degree clockwise rotation:" << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}