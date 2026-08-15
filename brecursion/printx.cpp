#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;

void print() {

    if (cnt == 5) {
        return;
    }

    cout << n << endl;
    cnt++;
    print();
}

int main() {

    cout << "Select end number: ";
    cin >> n;

    print();

    return 0;
}

/*Time complexity is O(N)*/