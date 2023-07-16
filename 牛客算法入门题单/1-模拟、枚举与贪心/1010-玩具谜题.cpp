#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> ls;
    map<string, int> dic;

    for (int i = 0; i < n; i ++) {
        int k; string s;
        cin >> k >> s;

        ls.push_back(s);
        dic[s] = k;
    }

    int idx = 0;
    for (int i = 0; i < m; i ++) {
        int flag, k; cin >> flag >> k;

        // 排列顺序为逆时针
        string s = ls[idx];
        if (flag == dic[s]) { // 顺时针
            idx = (idx - k + n) % n;
        }
        else {  // 逆时针
            idx = (idx + k) % n;
        }
    }

    cout << ls[idx] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}