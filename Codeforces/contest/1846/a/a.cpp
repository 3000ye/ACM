#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    int x, y;
} nail;

void solve() {
    int n; cin >> n;

    int res = 0;
    for (int i = 0; i < n; i ++) {
        int x, y; cin >> x >> y;

        if (y < x) res ++;
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}