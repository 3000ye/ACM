#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int p = 998244353;

ll binpow(ll a, ll b, ll p) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) res *= a;

        a = a * a % p;
        b >>= 1;
        res %= p;
    }

    return res;
}

void solve() {
    ll a, b; cin >> a >> b;
    cout << binpow(a, b, p) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}