#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls(n);

    ll sum = 0;
    for (auto &x : ls) {cin >> x; sum += x;}

    ll x = sum / n, y = sum % n;
    // 有 y 个 x + 1, n - y 个 x
    sort(ls.begin(), ls.end());
    ll res = 0, idx = 0;
    for (auto i : ls) {
        idx ++;
        if (idx <= n - y) res += abs(i - x);
        else res += abs(i - x - 1);
    }

    cout << res / 2 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}