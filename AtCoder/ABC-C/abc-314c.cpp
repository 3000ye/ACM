#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    string s;
    vector<vector<int>> ls(m + 1);
    
    cin >> s;
    for (int i = 0; i < n; i ++) {
        int c; cin >> c;
        ls[c].push_back(i);
    }

    for (int i = 1; i <= m; i ++) {
        vector<char> temp;
        for (auto c : ls[i]) temp.push_back(s[c]);
        char p = temp.back(); temp.pop_back();
        reverse(temp.begin(), temp.end());
        temp.push_back(p);
        reverse(temp.begin(), temp.end());

        for (int j = 0; j < temp.size(); j ++) {
            s[ls[i][j]] = temp[j];
        }
    }

    cout << s << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}