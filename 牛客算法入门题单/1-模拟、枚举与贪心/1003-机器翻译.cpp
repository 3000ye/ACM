#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int m, n; cin >> m >> n;
    queue<int> que;
    map<int, int> dic;

    int res = 0;
    while (n -- ) {
        int k; cin >> k;
        if (!dic.count(k) or dic[k] == 0) {
            res ++;
            que.push(k);
            dic[k] = 1;

            if (que.size() > m) {
                int x = que.front();
                que.pop();
                dic[x] = 0;
            }
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}