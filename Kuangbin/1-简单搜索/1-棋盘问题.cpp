#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100;
char dic[N][N];
bool ls[N];
int ans = 0, n, k; 

void dfs(int u, int v) {
    if (u == n) {
        // 摆放 n 层后，如果使用了 k 个棋子，则方案 +1
        if (v == k) ans ++;
        return;
    }

    for (int w = 0; w < n; w ++) {
        // 当前层有可以放置的地方，则选中然后递归下一层
        if (ls[w] == false and dic[u][w] == '#') {
            ls[w] = true;
            // 当前层已经放置了棋子，一层和一列只能放一个
            dfs(u + 1, v + 1);
            // 递归完成之后则恢复原样
            ls[w] = false;
        }
    }
    // 如果遍历完这一层都没有可以放棋子的位置，则继续递归下一层
    dfs(u + 1, v);
}

void solve() {
    while (cin >> n >> k) {
        if (n == -1 and k == -1) break;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) cin >> dic[i][j];
        }
        memset(ls, false, sizeof(ls));

        // 每次都重置 ans = 0
        ans = 0;
        dfs(0, 0);
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}