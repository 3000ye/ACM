#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef struct {
    int k, s;
} man;

bool cmp(man x, man y) {
    if (x.s > y.s) return true;
    else if (x.s == y.s) return x.k < y.k;
    else return false;
}

void solve() {
    int n, m; cin >> n >> m;
    m = m * 1.5;

    vector<man> ls;
    for (int i = 0; i < n; i ++) {
        int k, s; cin >> k >> s;

        ls.push_back(man{k, s});
    }

    sort(ls.begin(), ls.end(), cmp);

    int res = ls[m - 1].s, idx = 0;
    for (int i = 0; ls[i].s >= res; i ++) {
        idx ++;
    }

    cout << res << " " << idx << endl;
    for (int i = 0; ls[i].s >= res; i ++) {
        cout << ls[i].k << " " << ls[i].s << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}