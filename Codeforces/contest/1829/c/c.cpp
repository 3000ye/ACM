#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    // a: 01, b: 10, c: 11
    vector<int> a, b, c;
    while (n -- ) {
        int k; string s;
        cin >> k >> s;

        if (s == "01") a.push_back(k);
        if (s == "10") b.push_back(k);
        if (s == "11") c.push_back(k);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    if (a.size() == 0 or b.size() == 0) {
        if (c.size() == 0) cout << -1 << endl;
        else cout << c[0] << endl;
    }
    else {
        if (c.size() == 0) cout << a[0] + b[0] << endl;
        else cout << min(a[0] + b[0], c[0]) << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}