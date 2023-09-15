// Author: CastorYe
// Time: 2023-09-15 10:44:14
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    
    if (c & 1) a ++;
    
    if (a <= b) cout << "Second" << endl;
    else cout << "First" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
