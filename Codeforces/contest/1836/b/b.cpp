#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, k, g; cin >> n >> k >> g;
    ll t1 = k * g;
    ll t2 = (g / 2 + (g % 2) - 1) * n;

    if (t2 >= t1) cout << t1 << endl;
    else {
        ll res = k * g - g * ((t1 - t2) / (g) + ((t1 - t2) % (g) > 0));
        cout << max(res, 0ll) << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
