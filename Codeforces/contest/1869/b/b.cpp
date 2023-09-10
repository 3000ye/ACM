// Author: CastorYe
// Time: 2023-09-10 22:11:50
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    ll x, y;
} city;

void solve() {
    ll n, k, a, b; cin >> n >> k >> a >> b;
    vector<city> ls(n + 1);
    for (ll i = 1; i <= n; i ++) cin >> ls[i].x >> ls[i].y;

    // 都是 major city
    if (a <= k and b <= k) cout << 0 << endl;
    else if (a <= k and b > k) {  // 找离 b 最近的 major city
        ll res = 1e10;
        for (int i = 1; i <= k; i ++) {
            ll temp = abs(ls[b].x - ls[i].x) + abs(ls[b].y - ls[i].y);
            res = min(res, temp);
        }

        ll ans = abs(ls[a].x - ls[b].x) + abs(ls[a].y - ls[b].y);
        cout << min(res, ans) << endl;
    }
    else if (a > k and b <= k) {
        ll res = 1e10;
        for (int i = 1; i <= k; i ++) {
            ll temp = abs(ls[a].x - ls[i].x) + abs(ls[a].y - ls[i].y);
            res = min(res, temp);
        }

        ll ans = abs(ls[a].x - ls[b].x) + abs(ls[a].y - ls[b].y);
        cout << min(res, ans) << endl;
    }
    else {  // 如果都不是 major city，则有两种情况
        if (k >= 2) {  // a 和 b 都找一个 major city 来互连
            ll res1 = 1e10, res2 = 1e10;
            for (int i = 1; i <= k; i ++) {
                ll temp1 = abs(ls[b].x - ls[i].x) + abs(ls[b].y - ls[i].y);
                ll temp2 = abs(ls[a].x - ls[i].x) + abs(ls[a].y - ls[i].y);

                res1 = min(res1, temp1);
                res2 = min(res2, temp2);
            }

            ll ans = abs(ls[a].x - ls[b].x) + abs(ls[a].y - ls[b].y);
            cout << min(res1 + res2, ans) << endl;
        }
        else {  // a 和 b 直接相连
            ll res = abs(ls[a].x - ls[b].x) + abs(ls[a].y - ls[b].y);
            cout << res << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
