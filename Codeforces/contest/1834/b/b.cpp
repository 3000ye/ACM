#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string l, r; cin >> l >> r;
    while (l.size() < r.size()) l = '0' + l;

    int idx = l.size();
    for (int i = 0; i < l.size(); i ++) {
        if (l[i] != r[i]) {
            idx = i;
            swap(l[i], r[i]);
            break;
        }
    }

    for (int i = idx + 1; i < l.size(); i ++) l[i] = '0', r[i] = '9';
    int res = 0;
    for (int i = 0; i < l.size(); i ++) res += abs(l[i] - r[i]);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
