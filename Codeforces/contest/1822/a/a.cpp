#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int a[N], b[N];

void solve() {
    int n, t; cin >> n >> t;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];

    int res = 0, idx;
    for (int i = 0; i < n; i ++) {
        if (a[i] + i <= t) {
            if (res < b[i]) {
                res = b[i];
                idx = i + 1;
            }
        }
    }

    res ? cout << idx << endl : cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
