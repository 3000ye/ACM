#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    stack<int> stk;

    for (int i = 0; i < n; i ++) {
        int k; cin >> k;

        // 单调递减栈
        while (!stk.empty() and stk.top() >= k) stk.pop();

        if (!stk.empty()) cout << stk.top() << " ";
        else cout << "-1 ";

        stk.push(k);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}