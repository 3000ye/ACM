#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
    return a.second >= b.second;
}

void solve() {
    int n; cin >> n;

    vector<pii> ls;
    for (int i = 0; i < n; i ++) {
        int f, s; cin >> f >> s;
        ls.push_back({f, s});
    }

    sort(ls.begin(), ls.end(), cmp);
    int res = 0;
    
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (ls[i].first == ls[j].first) res = max(res, ls[i].second + ls[j].second / 2);
            else res = max(ls[i].second + ls[j].second);
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}