#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string x, y; cin >> x >> y;
    bitset<63> s(x), t(y);

    ll p = s.to_ulong(), q = t.to_ulong();

    if (p == 0 and q != 0) cout << "-1" << endl;
    else cout << abs(q - p) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}