#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int k; cin >> k;
            if (k == 0) cout << ".";
            else {
                cout << (char)((k - 1) + 'A');
            }
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}