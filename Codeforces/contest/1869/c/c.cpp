// Author: CastorYe
// Time: 2023-09-10 22:42:14
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n; i ++) {
        cout << i << " ";
        for (int j = 0; j < m; j ++) {
            if (j != i) cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
