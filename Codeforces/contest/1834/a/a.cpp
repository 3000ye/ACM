#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    int x = 0, y = 0;
    while (n -- ) {
        int k; cin >> k;
        if (k == 1) x ++;
        else y ++;
    }

    if (x >= y and y % 2 == 0) cout << 0 << endl;
    else if (x >= y) cout << 1 << endl;
    else {
        int res = (y - x + 1) / 2;
        y -= res;
        cout << res + (y & 1) << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
