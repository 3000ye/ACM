// Sleepy 黄川桂
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string ls; cin >> ls;

    int res = 0, flag = 1;
    for (int i = 1; ls[i]; i ++) {
        if (ls[i] == ls[i - 1]) flag ++;
        else {
            res += flag - 1; flag = 1;
        }
    }

    if (flag > 1) res += flag - 1;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}