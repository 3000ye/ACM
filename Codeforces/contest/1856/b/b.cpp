// Author: CastorYe
// Time: 2023-09-04 10:53:53
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    ll sum = 0;

    for (int i = 0; i < n; i ++) {
        ll x; cin >> x; sum += x - 1 - (x == 1);
    }

    cout << (sum >= 0 and n > 1 ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
