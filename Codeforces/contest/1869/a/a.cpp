// Author: CastorYe
// Time: 2023-09-10 22:05:16
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls(n + 1);
    for (int i = 1; i <= n; i ++) cin >> ls[i];

    if (n & 1) {
        cout << 4 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << 2 << " " << n << endl;
        cout << 2 << " " << n << endl;
    }
    else {
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
