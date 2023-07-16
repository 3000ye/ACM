#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, x1, x2, y1, y2; cin >> n >> x1 >> x2 >> y1 >> y2;
    int a1 = min(x1, n - x1), b1 = min(y1, n - y1);
    int a2 = min(x2, n - x2), b2 = min(y2, n - y2);

    cout << abs(min(a1, b1) - min(a2, b2) - 1) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
