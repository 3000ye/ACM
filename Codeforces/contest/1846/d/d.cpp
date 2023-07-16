#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ll n, d, h; cin >> n >> d >> h;

    ld res = (ld)n * d * h / 2;

    vector<ld> ls;
    for (int i = 0; i < n; i ++) {
        ld x; cin >> x; ls.push_back(x);
    }

    for (int i = 0; i < n - 1; i ++) {
        if (ls[i] + h > ls[i + 1]) {
            ld hh = ls[i] + h - ls[i + 1];
            ld dd = hh * d / h;
            ld s = hh * dd / 2;

            res -= s;
        }
    }

    printf("%.7LF", res);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
