// Author: CastorYe
// Time: 2023-09-04 22:51:04
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    
    cout << min(2 * x - 1, 2 * (y + z) + 1) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}