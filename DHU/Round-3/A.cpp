#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls;

    while (n -- ) {
        int k; cin >> k;
        ls.push_back(k);
    }

    sort(ls.begin(), ls.end());
    if (ls[0] >= 0) cout << ls[ls.size() - 1] << endl;
    else cout << ls[0] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}