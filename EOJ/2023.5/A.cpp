#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

int cnt(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else {
        int x = n / 2;
        return cnt(x) + 1;
    }
}

void solve() {
    int n; cin >> n;
    
    cout << cnt(n) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
