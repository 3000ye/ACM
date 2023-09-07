#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int dic[100][100];

void solve() {
    int n, m; cin >> n >> m;
    
    while (m -- ) {
        vector<int> ls(n);
        for (int i = 0; i < n; i ++) cin >> ls[i];

        for (int i = 1; i < n; i ++) {
            dic[ls[i - 1]][ls[i]] = dic[ls[i]][ls[i - 1]] = 1;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!dic[i][j]) {
                res ++;
                // cout << i << " " << j << endl;
            }
        }
    }

    cout << (res - n) / 2 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}