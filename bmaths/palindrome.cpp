#include <bits/stdc++.h>
using namespace std;
int main() {
    int ld;
    int n;
    int revnum = 0;
    cout << "Enter a number" << endl;
    cin >> n;
    int dup = n;   // ✅ store original number 
    while (n > 0) {
        ld = n % 10;
        revnum = (revnum * 10) + ld;
        n = n / 10;
    }
    if (dup == revnum) {
        cout << "The number you entered is a palindrome" << endl;
    }
    else {
        cout << "The number you entered is not a palindrome" << endl;
    }
}