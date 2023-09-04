// Author: CastorYe
// Time: 2023-09-04 16:51:24
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            char c; cin >> c;
            if (c != '.') cout << c;
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
