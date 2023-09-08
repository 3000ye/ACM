#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
int ls[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> ls[i];
    
    // 暴力搜索是否存在回路
    for (int i = 1; i <= n; i ++) {
        vector<int> res; int idx = i;
        
        while (!count(res.begin(), res.end(), ls[idx])) {
            res.push_back(ls[idx]); idx = ls[ls[idx]];
        }

        if (res[0] == ls[idx]) {
            cout << res.size() << endl;
            for (auto c : res) cout << c << " ";
            cout << endl;
            return;
        }
        else continue;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}