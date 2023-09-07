#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
int dic[11][11];
int used[11], ans;

void dfs(int v, int sum) {
    ans = max(ans, sum);

    used[v] = 1;
    for (int i = 1; i <= n; i ++) {
        if (!used[i] and dic[v][i]) dfs(i, sum + dic[v][i]);
    }
    // 恢复现场
    used[v] = 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b, c; cin >> a >> b >> c;

        dic[a][b] = dic[b][a] = c;
    }

    for (int i = 1; i <= n; i ++) dfs(i, 0);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}