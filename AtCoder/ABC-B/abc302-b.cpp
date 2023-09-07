#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> ls(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> ls[i]; ls[i] = '0' + ls[i];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (ls[i][j] == 's') {
                // 横线
                if (j >= 5) {  // 从右往左
                    if (ls[i][j - 1] == 'n' and ls[i][j - 2] == 'u' and ls[i][j - 3] == 'k' and ls[i][j - 4] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i << " " << j - 1 << endl;
                        cout << i << " " << j - 2 << endl;
                        cout << i << " " << j - 3 << endl;
                        cout << i << " " << j - 4 << endl;
                        return;
                    }
                }
                if (j <= m - 4) {  // 从左往右
                    if (ls[i][j + 1] == 'n' and ls[i][j + 2] == 'u' and ls[i][j + 3] == 'k' and ls[i][j + 4] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i << " " << j + 1 << endl;
                        cout << i << " " << j + 2 << endl;
                        cout << i << " " << j + 3 << endl;
                        cout << i << " " << j + 4 << endl;
                        return;
                    }
                }

                // 竖线
                if (i >= 5) {  // 从下往上
                    if (ls[i - 1][j] == 'n' and ls[i - 2][j] == 'u' and ls[i - 3][j] == 'k' and ls[i - 4][j] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i - 1 << " " << j << endl;
                        cout << i - 2 << " " << j << endl;
                        cout << i - 3 << " " << j << endl;
                        cout << i - 4 << " " << j << endl;
                        return;
                    }
                }
                if (i <= n - 4) {  // 从上往下
                    if (ls[i + 1][j] == 'n' and ls[i + 2][j] == 'u' and ls[i + 3][j] == 'k' and ls[i + 4][j] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i + 1 << " " << j << endl;
                        cout << i + 2 << " " << j << endl;
                        cout << i + 3 << " " << j << endl;
                        cout << i + 4 << " " << j << endl;
                        return;
                    }
                }

                // 斜线
                if (i >= 5 and j >= 5) {
                    if (ls[i - 1][j - 1] == 'n' and ls[i - 2][j - 2] == 'u' and ls[i - 3][j - 3] == 'k' and ls[i - 4][j - 4] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i - 1 << " " << j - 1 << endl;
                        cout << i - 2 << " " << j - 2 << endl;
                        cout << i - 3 << " " << j - 3 << endl;
                        cout << i - 4 << " " << j - 4 << endl;
                        return;
                    }
                }
                if (i >= 5 and j <= m - 4) {
                    if (ls[i - 1][j + 1] == 'n' and ls[i - 2][j + 2] == 'u' and ls[i - 3][j + 3] == 'k' and ls[i - 4][j + 4] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i - 1 << " " << j + 1 << endl;
                        cout << i - 2 << " " << j + 2 << endl;
                        cout << i - 3 << " " << j + 3 << endl;
                        cout << i - 4 << " " << j + 4 << endl;
                        return ;
                    }
                }
                if (i <= n - 4 and j >= 5) {
                    if (ls[i + 1][j - 1] == 'n' and ls[i + 2][j - 2] == 'u' and ls[i + 3][j - 3] == 'k' and ls[i + 4][j - 4] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i + 1 << " " << j - 1 << endl;
                        cout << i + 2 << " " << j - 2 << endl;
                        cout << i + 3 << " " << j - 3 << endl;
                        cout << i + 4 << " " << j - 4 << endl;
                        return;
                    }
                }
                if (i <= n - 4 and j <= m - 4) {
                    if (ls[i + 1][j + 1] == 'n' and ls[i + 2][j + 2] == 'u' and ls[i + 3][j + 3] == 'k' and ls[i + 4][j + 4] == 'e') {
                        cout << i << " " << j << endl;
                        cout << i + 1 << " " << j + 1 << endl;
                        cout << i + 2 << " " << j + 2 << endl;
                        cout << i + 3 << " " << j + 3 << endl;
                        cout << i + 4 << " " << j + 4 << endl;
                        return;
                    }
                }
            }
            else continue;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}