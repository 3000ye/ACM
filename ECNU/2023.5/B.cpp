#include "bits/stdc++.h"
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int m, x, a, b; cin >> m >> x >> a >> b;
    int s = m / x;
    ld res = 0.0;

    while (s >= 0) {
        res = max(res, (ld)(a + m - s * x) / (ld)(a + m - s * x + b - min(b, s)));
        s --;
    }

    printf("%.9LF\n", res);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
