#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
int res[N];

void solve() {
    int n, m; cin >> n >> m;
    while (m -- ) {
        int a, b; cin >> a >> b;
        res[b] ++;
    }

    int cnt = 0, idx = 1;
    for (int i = 1; i <= n; i ++) {
        if (!res[i]) {
            cnt ++; idx = i;
        }
    }

    if (cnt == 1) cout << idx << endl;
    else cout << "-1" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}