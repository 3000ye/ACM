#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    ll a, b;
} day;

bool cmp(day x, day y) {
    return x.a > y.a;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<day> ls(n);
    for (auto &day : ls) cin >> day.a >> day.b;

    sort(ls.begin(), ls.end(), cmp);

    ll res = 0;
    for (auto day : ls) {
        res += day.b;

        if (res > k) {
            cout << day.a + 1 << endl;
            return;
        }
    }

    cout << 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}