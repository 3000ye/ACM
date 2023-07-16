#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    int flag = 1, odd = 0, even = 0;

    for (int i = 0; i < n; i ++) {
        int x; cin >> x;

        if (x & 1) {
            if (x < odd) flag = 0;
            odd = x;
        }
        else {
            if (x < even) flag = 0;
            even = x;
        }
    }

    flag ? cout << "Yes" << endl : cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}