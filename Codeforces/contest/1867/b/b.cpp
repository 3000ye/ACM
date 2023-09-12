// Author: CastorYe
// Time: 2023-09-11 22:37:05
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void dfs(vector<int> &ls, string s, int k) {
    
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> ls(n + 1);
    dfs(ls, s, 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
