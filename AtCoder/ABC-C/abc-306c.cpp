#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    unordered_map<int, vector<int>> dic;

    for (int i = 1; i <= 3 * n; i ++) {
        int k; cin >> k;
        dic[k].push_back(i);
    }

    vector<pair<int, int>> ls;
    for (int i = 1; i <= n; i ++) {
        sort(dic[i].begin(), dic[i].end());
        ls.push_back({i, dic[i][1]});
    }

    sort(ls.begin(), ls.end(), cmp);
    for (auto i : ls) cout << i.first << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}