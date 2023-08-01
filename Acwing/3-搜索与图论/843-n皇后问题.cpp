#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) cout << g[i][j];
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i ++) {
        if (!col[i] and !dg[u + i] and !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;  // 判断这个数字是否已被输出过
            dfs(u + 1);

            // 恢复现场
            g[u][i]= '.';
            col[i] = dg[u + i] = udg[n - u + i] = false;
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) g[i][j] = '.';
    }

    dfs(0);

    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}