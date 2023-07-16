#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 50;
int dic[N][N];

void solve() {
    int n; cin >> n;

    int x = 1, y = (n + 1) / 2, m = n * n;

    dic[x][y] = 1;
    for (int i = 2; i <= m; i ++) {
        if (x == 1 and y != n) {
            x = n, y ++;
        }
        else if (x != 1 and y == n) {
            x --, y = 1;
        }
        else if (x == 1 and y == n) {
            x ++;
        }
        else {
            if (dic[x - 1][y + 1] == 0) x --, y ++;
            else x ++;
        }

        dic[x][y] = i;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) cout << dic[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}