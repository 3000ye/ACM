#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    unordered_map<string, int> dic;
    int res = 0;
    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        string t = s;
        reverse(t.begin(), t.end());

        if (dic[s] == 0 and dic[t] == 0) res ++;

        dic[s] ++; dic[t] ++;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}