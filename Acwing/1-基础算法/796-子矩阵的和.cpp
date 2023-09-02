#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1010;
int dic[N][N], res[N][N];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> dic[i][j];
            res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + dic[i][j];
        }
    }

    while (q -- ) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        cout << res[x2][y2] - res[x1 - 1][y2] - res[x2][y1 - 1] + res[x1 - 1][y1 - 1] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}