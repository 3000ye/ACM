#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int a, b, o, k; cin >> a >> b >> o >> k;

    int res = 0;
    while (a + b >= k) {
        res ++;

        int x = k;
        if (a >= x) a -= x, b += x, x = 0;
        else x -= a, b += a, a = 0;

        if (b >= x) b -= x, o += x, x = 0;
        else x -= b, o += b, b = 0;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}