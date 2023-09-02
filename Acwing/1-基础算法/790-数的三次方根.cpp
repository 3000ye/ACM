#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ld n; cin >> n;
    ld i = -10010.0, j = 10010.0;

    while (i + 0.0000001 < j) {
        ld mid = (i + j) / 2;
        if ((mid * mid * mid) < n) i = mid;
        else j = mid;
    }

    printf("%.6LF", i);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}