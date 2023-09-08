// Author: CastorYe
// Time: 2023-09-08 15:23:03
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    int res = 1e9 + 10;

    for (int i = 0; i < n; i ++) {
        int d, s; cin >> d >> s;

        res = min(res, (s - 1) / 2 + d);
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
