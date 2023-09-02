#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5;
int ls[N], res[N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> ls[i];
        res[i] = ls[i] - ls[i - 1];  // 差分序列
    }

    while (m -- ) {
        int l, r, c; cin >> l >> r >> c;
        res[r + 1] -= c, res[l] += c;
    }

    for (int i = 1; i <= n; i ++) {
        ls[i] = res[i] + ls[i - 1];  // 求前缀和
        cout << ls[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}