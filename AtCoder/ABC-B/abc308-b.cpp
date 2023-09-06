#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> ls(n), ls_d(m);
    unordered_map<string, int> dic;

    for (int i = 0; i < n; i ++) cin >> ls[i];
    for (int i = 0; i < m; i ++) cin >> ls_d[i];

    int p0; cin >> p0;
    for (int i = 0; i < m; i ++) {
        int p; cin >> p; dic[ls_d[i]] = p;
    }

    int sum = 0;
    for (auto i : ls) {
        if (!dic[i]) sum += p0;
        else sum += dic[i];
    }

    cout << sum << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}