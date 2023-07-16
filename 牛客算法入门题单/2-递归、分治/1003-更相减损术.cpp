#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int gcd(int a, int b) {
    return a == b ? b : gcd(b, abs(a - b));
}

void solve() {
    int a, b; cin >> a >> b;

    cout << gcd(a, b) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}