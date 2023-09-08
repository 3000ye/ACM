// Author: CastorYe
// Time: 2023-09-08 15:15:45
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    double a, b, c; cin >> a >> b >> c;

    double x = abs(a - b) / 2;
    double res = x / c; int flag = (int)res;

    if (res == flag) cout << flag << endl;
    else cout << flag + 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
