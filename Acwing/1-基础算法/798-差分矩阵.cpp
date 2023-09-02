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
            res[i][j] = dic[i][j] - dic[i - 1][j] - dic[i][j - 1] + dic[i - 1][j - 1];
        }
    }

    while (q -- ) {
        int x1, y1, x2, y2, c; cin >> x1 >> y1 >> x2 >> y2 >> c;

        res[x1][y1] += c, res[x1][y2 + 1] -= c;
        res[x2 + 1][y1] -= c, res[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            dic[i][j] = dic[i][j - 1] + dic[i - 1][j] - dic[i - 1][j - 1] + res[i][j];
            cout << dic[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}