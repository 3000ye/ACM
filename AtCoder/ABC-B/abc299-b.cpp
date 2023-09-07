#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
    return a.second >= b.second;
}

void solve() {
    int n, t; cin >> n >> t;
    vector<pii> ls(n);
    vector<pii> res, res0;

    for (auto &x : ls) cin >> x.first;
    for (auto &x : ls) cin >> x.second;

    for (int i = 0; i < n; i ++) {
        if (ls[i].first == t) res.push_back({i + 1, ls[i].second});
        if (ls[i].first == ls[0].first) res0.push_back({i + 1, ls[i].second});
    }

    if (res.size() >= 1) {
        sort(res.begin(), res.end(), cmp);
        cout << res[0].first << endl;
    }
    else {
        sort(res0.begin(), res0.end(), cmp);
        cout << res0[0].first << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}