#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;

void solve() {
    int m; cin >> m;

    ll res = m - 1;
    for (int i = 0; i < m; i ++) {
        res = res * m / (m - 1);
        res ++;

        res = res % mod;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}