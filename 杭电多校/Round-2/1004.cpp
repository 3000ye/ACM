// Sleepy 黄川桂
// 牛客：https://ac.nowcoder.com/acm/contest/21763/1009
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;

ll quick_pow(ll m, ll k, ll p) {
    ll res = 1 % p, t = m;
    while (k)
    {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }

    return res;
}

void solve() {
    ll n; cin >> n;
    ll res = quick_pow(2, n - 1, mod) - 1;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}