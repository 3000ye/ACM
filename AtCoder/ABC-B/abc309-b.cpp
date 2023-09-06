#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
char dic[N][N], res[N][N];

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> dic[i][j]; res[i][j] = dic[i][j];
        }
    }

    for (int j = 2; j <= n; j ++) res[1][j] = dic[1][j - 1];
    for (int i = 2; i <= n; i ++) res[i][n] = dic[i - 1][n];
    for (int j = n - 1; j >= 1; j --) res[n][j] = dic[n][j + 1];
    for (int i = n - 1; i >= 1; i --) res[i][1] = dic[i + 1][1];

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) cout << res[i][j];
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}