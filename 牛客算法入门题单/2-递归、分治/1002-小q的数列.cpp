#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll func(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return func(n / 2) + func(n % 2);
}

void solve() {
    ll n; cin >> n;

    ll x = func(n);
    cout << x << " " << (1ll << x) - 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}