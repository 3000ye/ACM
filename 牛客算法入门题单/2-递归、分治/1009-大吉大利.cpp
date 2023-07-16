#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n;

    // 找规律发现：
    // ans(n) = 2 * sum_{i = 1}^{n} 3^(n - 1)
    while (cin >> n) {
        ll x = 1, res = 0;

        for (int i = 0; i < n; i ++) {
            res += x;
            x *= 3;
        }

        cout << res * 2 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}