#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ll l, r; cin >> l >> r;

    ll res = ll(sqrt(r)) - ll(sqrt(l));
    if (ll(sqrt(l)) * ll(sqrt(l)) == l) res ++;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}