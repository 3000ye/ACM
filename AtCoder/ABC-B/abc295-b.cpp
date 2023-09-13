#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char dic[30][30], res[30][30];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> dic[i][j]; res[i][j] = dic[i][j];
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (isdigit(dic[i][j])) {
                int k = dic[i][j] - '0';

                for (int p = i - k; p <= i + k; p ++) {
                    for (int q = j - k; q <= j + k; q ++) {
                        // 判断边界与曼哈顿距离
                        if (p >= 1 and p <= n and q >= 1 and q <= m and abs(p - i) + abs(q - j) <= k) {
                            res[p][q] = '.';
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cout << res[i][j];
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}