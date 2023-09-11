#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int b1, b2, r1, r2, k;
    bool flag1 = true, flag2 = true;

    for (int i = 0; i < 8; i ++) {
        char c; cin >> c;

        if (c == 'B' and flag1) {b1 = i + 1; flag1 = false;}
        if (c == 'B' and !flag1) b2 = i + 1;
        if (c == 'R' and flag2) {r1 = i + 1; flag2 = false;}
        if (c == 'R' and !flag2) r2 = i + 1;
        if (c == 'K') k = i + 1;
    }

    // cout << b1 << " " << b2 << endl;
    // cout << r1 << " " << k << " " << r2 << endl;
    if ((b1 ^ b2) & 1 and r1 < k and k < r2) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}