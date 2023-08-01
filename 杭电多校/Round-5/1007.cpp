#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;

void solve() {
    ll n, m; ld a, b; cin >> n >> m >> a >> b;

    ll E = 0;
    ld p = a / b, q = 1 - p;
    for (int i = 0; i <= n; i ++) {
        // 赢 i 次
        ld temp = pow(p, i) * pow(q, n - i);
        ld res = 0;
        for (int j = 0; j < i; j ++) {
            res += temp * pow(j, m);
        }

        E += (ll)res;
        E = (E % mod + mod) % mod;
    }

    cout << E << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}