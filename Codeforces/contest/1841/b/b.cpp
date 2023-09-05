// Author: CastorYe
// Time: 2023-09-05 09:55:36
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
int ls[N];

void solve() {
    int n; cin >> n;

    bool flag = 1;
    int x; cin >> x; cout << "1";
    int head = x, mn = x, mx = 1e9 + 10;

    for (int i = 1; i < n; i ++) {
        cin >> x;

        if (mn <= x and x <= mx) {
            mn = x; cout << "1";
        }
        else {
            if (flag and x <= head) {
                mn = x, mx = head, flag = 0;
                cout << "1";
            }
            else cout << "0";
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
