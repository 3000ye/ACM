#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    vector<int> res;
    for (int i = 0; i < n - 1; i ++) {
        res.push_back(abs(ls[i] - ls[i + 1]));
    }
    sort(res.begin(), res.end());

    ll ans = 0;
    for (int i = 0; i < n - k; i ++) {ans += res[i];}

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
