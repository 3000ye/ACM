// Author: CastorYe
// Time: 2023-09-04 21:37:07
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (a + b >= 10 or a + c >= 10 or b + c >= 10) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
