#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

ll get(ll x) {
    return x * (x + 1) / 2;
}

void solve() {
    ll n; cin >> n;
    cout << n * 4 + get(n - 1) + get(n - 2) + 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
