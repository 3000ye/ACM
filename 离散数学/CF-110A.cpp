#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string ls; cin >> ls;

    int flag = 1;
    for (auto s : ls) {
        if (s != '4' or s != '7') {
            flag = 0;
            break;
        }
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

