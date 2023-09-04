// Author: CastorYe
// Time: 2023-09-04 21:40:25
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    int idx = 0, res = 0;

    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        if (x <= 10 and res < y) {
            res = y;
            idx = i;
        }
    }

    cout << idx << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
