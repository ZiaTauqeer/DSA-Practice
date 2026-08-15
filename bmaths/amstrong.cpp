#include <bits/stdc++.h>
using namespace std;

int main() {
    int ld;
    int n;
    int sum=0;
    cout << "Enter a number" << endl;
    cin >> n;
    int dup = n;   // ✅ store original number
    while (n > 0) {
        ld = n % 10;
        sum = sum + (ld*ld*ld);
        n = n / 10;
    }
    if (dup == sum) {
        cout << "The number you entered is an amstrong number" << endl;
    }
    else {
        cout << "The number you entered is not an amstrong number" << endl;
    }
}