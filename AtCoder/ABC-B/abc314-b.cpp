#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    unordered_map<int, unordered_map<int, int>> dic;

    for (int i = 0; i < n; i ++) {
        int c; cin >> c;
        while (c -- ) {
            int a; cin >> a;
            dic[i][a] = 1;
        }
    }

    int x; cin >> x;
    vector<pair<int, int>> ls;
    for (int i = 0; i < n; i ++) {
        if (dic[i][x] == 1) ls.push_back(pair<int, int> (i, dic[i].size()));
    }

    if (ls.size() == 0) {
        cout << 0 << endl; return ;
    }

    sort(ls.begin(), ls.end(), cmp);
    int res = ls[0].second;

    vector<int> ans;
    for (auto i : ls) {
        if (i.second > res) break;
        ans.push_back(i.first + 1);
    }
    
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}