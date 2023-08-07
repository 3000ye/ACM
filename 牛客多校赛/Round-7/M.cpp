#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    int x = n / 10;
    int y = n % (x ** 10);

    int res = 0;
    for (int i = 1; i <= x; i ++) {
        res += i * 9 * (10 ** (i - 1));
    }

    res += x * y;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}