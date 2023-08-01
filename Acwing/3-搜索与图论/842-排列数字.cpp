#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 10;
int path[N], n;
bool st[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) cout << path[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;  // 判断这个数字是否已被输出过
            dfs(u + 1);

            // 恢复现场
            path[u] = 0;
            st[i] = false;
        }
    }
}

void solve() {
    cin >> n;

    dfs(0);

    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}