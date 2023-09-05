// Author: CastorYe
// Time: 2023-09-05 11:52:18
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;

    if (n % 3 != 0 and n != m) {cout << "NO" << endl; return ;}

    queue<int> que; que.push(m);

    while (!que.empty()) {
        int x = que.front(); que.pop();

        if (x == n) {cout << "YES" << endl; return ;}
        else {
            if (x % 2 == 0) {
                if (x / 2 * 3 <= n) que.push(x / 2 * 3);
            }

            if (x * 3 <= n) que.push(x * 3);
        }
    }

    cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
