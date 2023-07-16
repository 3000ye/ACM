#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(int n, int m) {
    if (n < m) return false;
    if (n == m) return true;
    if (n % 3 == 0) {
        int x = n / 3, y = x * 2;
        if (x == m or y == m) return true;
        else return check(x, m) or check(y, m);
    }
    else return false;
}

void solve() {
    int n , m; cin >> n >> m;

    check(n, m) ? cout << "YES" << endl : cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}

