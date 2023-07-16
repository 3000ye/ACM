#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;

    int flag = 0;

    while (k -- ) {
        int a, b; cin >> a >> b;
        if (a != x and b != y) flag = 1;
    }

    flag ? cout << "NO" << endl : cout << "YES" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
