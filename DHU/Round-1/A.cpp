#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    map<int, int> dic;
    int top = 0;
    for (int i = 0; i < n; i ++) {
        int k; cin >> k;
        top = max(top, k);
        dic[k] ++;
    }

    int flag = 1, res;
    for (int i = 1; i <= top; i ++) {
        if (!dic.count(i)) {flag = 0; break;}
        if (dic[i] > dic[i - 1]) {flag = 0; break;}
    }

    flag ? cout << "YES" << endl : cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}