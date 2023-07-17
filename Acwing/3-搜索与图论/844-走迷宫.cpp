#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110, mmax = 99999;
int dic[N][N], res[N][N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> dic[i][j];
    }

    memset(res, -1, sizeof(res));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (dic[i][j] == 0) {
                if (i == 1 and j == 1) {
                    res[i][j] = 0;
                }
                else if (i == 1 and j != 1) {
                    if (dic[i][j - 1] == 0) res[i][j] = res[i][j - 1] + 1;
                }
                else if (i != 1 and j == 1) {
                    if (dic[i - 1][j] == 0) res[i][j] = res[i - 1][j] + 1;
                }
                else {
                    int x = mmax;
                    if (dic[i - 1][j] == 0 and res[i - 1][j] != -1) x = min(x, res[i - 1][j] + 1);
                    if (dic[i][j - 1] == 0 and res[i][j - 1] != -1) x = min(x, res[i][j - 1] + 1);

                    if (x != mmax) res[i][j] = x;
                }
            }
        }
    }

    cout << "--------------------------" << endl;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cout << res[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}