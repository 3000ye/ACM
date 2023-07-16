#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    ll x, y;
} man;

bool cmp(man a, man b) {
    if (a.x > b.x) return true;
    else if (a.x == b.x) return a.y < b.y;
    else return false;
}

void solve() {
    ll n, m, h; cin >> n >> m >> h;

    vector<man> res;

    for (ll i = 0; i < n; i ++) {
        vector<ll> ls;
        for (ll j = 0; j < m; j ++) {
            ll k; cin >> k; ls.push_back(k);
        }

        sort(ls.begin(), ls.end());

        ll x = 0, y = 0, t = 0, idx = 0;
        while (idx < m) {
            if (t + ls[idx] > h) break;
            else {
                t += ls[idx], y += t;
                x ++, idx ++;
            }
        }

        // cout << x << " " << y << " " << t << endl;
        res.push_back(man{x, y});
    }

    ll r_x = res[0].x, r_y = res[0].y;
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < n; i ++) {
        if (res[i].x == r_x and res[i].y == r_y) {
            cout << i + 1 << endl;
            break;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}