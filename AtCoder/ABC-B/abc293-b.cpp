#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls(n + 1);
    vector<int> flag(n + 1);
    for (int i = 1; i <= n; i ++) cin >> ls[i];

    for (int i = 1; i <= n; i ++) {
        if (flag[ls[i]] == 0) {
            flag[ls[ls[i]]] = 1;
            cout << i << " " << ls[i] << " " << ls[ls[i]] << endl;
        }
    }
    cout << "=======================" << endl;
    for (int i = 1; i <= n; i ++) {
        if (flag[ls[i]] == 0) {
            flag[ls[ls[i]]] = 1;
            cout << i << " " << ls[i] << " " << ls[ls[i]] << endl;
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i ++) {
        if (flag[ls[i]] == 0) res.push_back(i);
    }

    cout << res.size() << endl;
    for (auto i : res) cout << i << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}