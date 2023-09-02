#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N], res[N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> ls[i];
        res[i] = res[i - 1] + ls[i];
    }

    while (m -- ) {
        int l, r; cin >> l >> r;
        cout << res[r] - res[l - 1] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}