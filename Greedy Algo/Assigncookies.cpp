#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int gIndex = 0;
    int sIndex = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (sIndex < s.size() && gIndex < g.size()) {

        if (s[sIndex] >= g[gIndex]) {
            sIndex++;
            gIndex++;
        }
        else {
            sIndex++;
        }
    }

    return gIndex;
}

int main() {

    int n, m;

    // Number of children
    cin >> n;

    vector<int> g(n);

    // Greed factor of each child
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    // Number of cookies
    cin >> m;

    vector<int> s(m);

    // Size of each cookie
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    int ans = findContentChildren(g, s);

    cout << "Maximum number of content children: " << ans << endl;

    return 0;
}