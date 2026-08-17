//if 0 is founf in the matrix turn that entire row and column to 0
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

    int col0 = 1;

    // Step 1: Mark the first row and first column
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (matrix[i][j] == 0) {

                // Mark the i-th row
                matrix[i][0] = 0;

                // Mark the j-th column
                if (j != 0) {
                    matrix[0][j] = 0;
                }
                else {
                    // First column needs to become zero
                    col0 = 0;
                }
            }
        }
    }

    // Step 2: Set the inner part of the matrix to zero
    for (int i = 1; i < n; i++) {

        for (int j = 1; j < m; j++) {

            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: If the first row was marked,
    // make the entire first row zero
    if (matrix[0][0] == 0) {

        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: If the first column was marked,
    // make the entire first column zero
    if (col0 == 0) {

        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    // Print the final matrix
    cout << "Matrix after setting zeroes:" << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}