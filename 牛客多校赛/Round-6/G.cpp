#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(int x, int y, int z) {
    if (z == abs(x - y) or z == __gcd(x, y)) return true;
    if (z == x or z == y) return true;
    if (z > abs(x - y) or x == y) return false;
    
    return check(min(x, y), __gcd(x, y), z);
}

void solve() {
    int x, y, z; cin >> x >> y >> z;

    if (check(x, y, z)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}