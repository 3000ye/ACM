#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char dic[550][550];
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> dic[i][j];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (dic[i][j] == '.') {
                int temp = 0;

                for (int k = 0; k < 4; k ++) {
                    int x = i + mx[k], y = j + my[k];

                    if (dic[x][y] == '#') temp ++;
                }
                if (temp >= 2) {
                    cout << i << " " << j << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}