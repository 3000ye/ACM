#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<ll> ls;
    for (int i = 0; i < n; i ++) {
        int k; cin >> k;
        ls.push_back(k);
    }

    sort(ls.begin(), ls.end());
    int l = ls.size();
    ll res = ls[l - 2] * ls[l - 1];

    if (ls[0] < 0 and ls[1] < 0) {
        cout << max(ls[0] * ls[1], res) << endl;
    }
    else cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
