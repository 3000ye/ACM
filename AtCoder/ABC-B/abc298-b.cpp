#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int A[110][110], B[110][110], C[110][110];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {cin >> A[i][j]; C[i][j] = A[i][j];}
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) cin >> B[i][j];
    }

    for (int k = 0; k < 4; k ++) {
        // 判断是否满足条件
        bool flag = true;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (A[i][j] == 1 and B[i][j] != 1) {
                    flag = false; break;
                }
            }
            if (!flag) break;
        }

        if (flag) {cout << "Yes" << endl; return ;}

        // rotate
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                C[i][j] = A[n + 1 - j][i];
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                A[i][j] = C[i][j];
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}