#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 510;
const ll mod = 1e9 + 7;
ll A[N][N], B[N][N], res[N][N];

void solve() {
    int n, p, m; cin >> n >> p >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= p; j ++) cin >> A[i][j];
    }
    for (int i = 1; i <= p; i ++) {
        for (int j = 1; j <= m; j ++) cin >> B[i][j];
    }

    for (int i = 1; i <= n; i ++) {
        for (int k = 1; k <= p; k ++) {
            ll s = A[i][k];

            for (int j = 1; j <= m; j ++) {
                res[i][j] += s * B[k][j];
                res[i][j] = (res[i][j] % mod + mod) % mod;
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cout << res[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}