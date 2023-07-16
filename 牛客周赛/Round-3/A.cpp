#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int x; cin >> x;

    for (int i = 0; i < 10; i ++) {
        int y = x * 10 + i;

        if (y % 7 == 0) {cout << y << endl; break;}
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}