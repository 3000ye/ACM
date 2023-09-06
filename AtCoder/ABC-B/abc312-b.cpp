#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
char dic[N][N];

bool check(int i, int j) {
    // 判断以 (i, j) 为左上角的 9x9 区域是否为 TaK Code

    bool flag = true;
    // top-left
    for (int p = i; p < i + 3; p ++) {
        for (int q = j; q < j + 3; q ++) {
            if (dic[p][q] != '#') flag = false;
        }
    }

    // bottom-right
    for (int p = i + 6; p < i + 9; p ++) {
        for (int q = j + 6; q < j + 9; q ++) {
            if (dic[p][q] != '#') flag = false;
        }
    }

    // top-left line
    for (int p = i; p < i + 4; p ++) {
        if (dic[p][j + 3] != '.') flag = false;
    }
    for (int q = j; q < j + 4; q ++) {
        if (dic[i + 3][q] != '.') flag = false;
    }

    // bottom-right line
    for (int p = i + 5; p < i + 9; p ++) {
        if (dic[p][j + 5] != '.') flag = false;
    }
    for (int q = j + 5; q < j + 9; q ++) {
        if (dic[i + 5][q] != '.') flag = false;
    }

    return flag;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> dic[i][j];
    }

    for (int i = 1; i <= n - 8; i ++) {
        for (int j = 1; j <= m - 8; j ++) {
            if (check(i, j)) cout << i << " " << j << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}