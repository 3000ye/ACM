#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string x, y; cin >> x >> y;

    while (x.size() < y.size()) x += x;

    if (x == y) cout << "Smart People's Big Win!" << endl;
    else cout << "Lazy Dog's Great Failure..." << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}