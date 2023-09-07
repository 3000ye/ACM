#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(int a, int b) {return a > b;}

void solve() {
    int n; cin >> n;
    map<int, vector<int>> dic;

    for (int i = 0; i < n; i ++) {
        int f, s; cin >> f >> s;
        dic[f].push_back(s);
    }

    int res = 0;
    vector<int> best;
    for (auto [k, v] : dic) {
        sort(v.begin(), v.end(), cmp);

        if (v.size() >= 2) res = max(res, v[0] + v[1] / 2);
        if (v.size() >= 1) best.push_back(v[0]);
    }

    sort(best.begin(), best.end(), cmp);
    if (best.size() >= 2) res = max(res, best[0] + best[1]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}