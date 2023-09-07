#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    if (n <= 1000) cout << n << endl;
    else if (n <= 10000) cout << n / 10 << "0" << endl;
    else if (n <= 100000) cout << n / 100 << "00" << endl;
    else if (n <= 1000000) cout << n / 1000 << "000" << endl;
    else if (n <= 10000000) cout << n / 10000 << "0000" << endl;
    else if (n <= 100000000) cout << n / 100000 << "00000" << endl;
    else cout << n  1000000 << "000000" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}