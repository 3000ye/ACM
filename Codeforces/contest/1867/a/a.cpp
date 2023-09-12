// Author: CastorYe
// Time: 2023-09-11 22:36:19
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls(n);
    for (auto &x : ls) cin >> x;

    queue<int> que;
    unordered_map<int, int> dic;
    for (int i = 0; i < n; i ++) que.push(i + 1);
    for (int i = 0; i < n; i ++) {
        while (dic[ls[i] - que.front()]) {
            int x = que.front();
            que.pop(); que.push(x);
        }
        cout << que.front() << " ";
        dic[ls[i] - que.front()] ++;
        que.pop();
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
