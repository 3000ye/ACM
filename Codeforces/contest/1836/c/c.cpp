#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int a, b, c, k; cin >> a >> b >> c >> k;
    if (a > c or b > c) {cout << -1 << endl; return ;}

    ll xl = 1, yl = 1, zl = 1;
    while (a -- ) xl *= 10;
    while (b -- ) yl *= 10;
    while (c -- ) zl *= 10;
    ll xr = xl * 10 - 1;
    ll yr = yl * 10 - 1;
    ll zr = zl * 10 - 1;

    for (int i = xl; i <= xr; i ++) {
        if (i + yr < zr) continue;

        
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
