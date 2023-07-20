#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(ll x, ll y) {
    for (int i = 0; i <= 20; i ++ ) {
        ll z = y * y / pow(10, i);
        if (z == x) return true;
    }

    return false;
}

void solve() {
    ll x; cin >> x;

    ll l = 0, r = 1e9;
    int flag = 0;
    while (l < r) {
        ll mid = (l + r) >> 1;

        if (check(x, mid)) {
            flag = 1;
            cout << mid << endl;
            break;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}