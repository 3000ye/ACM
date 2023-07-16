#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string ls; cin >> ls;

    if (ls.size() <= 10) cout << ls << endl;
    else {
        cout << ls[0] << ls.size() - 2 << ls[ls.size() - 1] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) {solve();}
    return 0;
}
