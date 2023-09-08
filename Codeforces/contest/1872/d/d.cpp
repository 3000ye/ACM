// Author: CastorYe
// Time: 2023-09-08 16:18:36
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    ll s = n / x, t = n / y;

    // 公共数字
    ll mom = (x * y) / __gcd(x, y);
    ll k = n / mom;

    ll sum = (2 * n - s + k + 1) * (s - k) / 2;
    sum -= (t - k + 1) * (t - k) / 2;

    cout << sum << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
