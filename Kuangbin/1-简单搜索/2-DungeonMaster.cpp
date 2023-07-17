#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 35;
char dic[N][N][N];  // 存三维地图
int move_x[6] = {1, -1, 0, 0, 0, 0};
int move_y[6] = {0, 0, 1, -1, 0, 0};
int move_z[6] = {0, 0, 0, 0, 1, -1};
int vis[N][N][N];
int l, r, c;

typedef struct node {
    int x, y, z;
    int t;
} node;


void solve() {
    while (cin >> l >> r >> c) {
        if (l == r == c == 0) break;

        for (int i = 0; i < l; i ++) {
            for (int j = 0; j < r; j ++) {
                for (int k = 0; k < c; k ++) cin >> dic[i][j][k];
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