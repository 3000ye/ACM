#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ll sum = 0;
    for (int i = 0; i < 64; i ++) {
        int x; cin >> x;
        if (x == 1) {
            ll temp = pow((ll)2, i);
            sum += pow(2, i);
        }
    }

    cout << sum << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}