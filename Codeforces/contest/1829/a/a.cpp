#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

string ls = "codeforces";

void solve() {
    string s; cin >> s;

    int cnt = 0;
    for (int i = 0; i < 10; i ++) {
        if (ls[i] != s[i]) cnt ++;
    }

    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}

