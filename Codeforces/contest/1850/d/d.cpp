// Author: CastorYe
// Time: 2023-09-04 15:22:02
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
int ls[N];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    sort(ls, ls + n);

    stack<int> stk; int res = 0;
    for (int i = 0; i < n; i ++) {
        if (!stk.empty() and abs(stk.top() - ls[i]) > k) {
            res = max(res, (int)stk.size());
            while (!stk.empty()) stk.pop();
        }

        stk.push(ls[i]);
    }

    if (!stk.empty()) res = max(res, (int)stk.size());
    cout << n - res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
