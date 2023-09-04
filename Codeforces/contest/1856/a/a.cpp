// Author: CastorYe
// Time: 2023-09-04 10:36:11
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100;
int ls[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    int res = 0;
    for (int i = 0; i < n - 1; i ++) {
        if (ls[i] > ls[i + 1]) res = max(res, ls[i]);
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
