// Sleepy 黄川桂
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    ll n, k; cin >> n >> k;
    string ls; cin >> ls;

    stack<int> stk; vector<char> res;
    for (auto s : ls) {
        if (s == '0') {
            if (k) stk.push(s);
            else res.push_back('0');
        }
        else {
            if (!stk.empty()) {
                int x = stk.size();
                while (x --) res.push_back('1');
                while (!stk.empty()) stk.pop();
                k --;
            }

            res.push_back('1');
        }
    }

    if (!stk.empty()) {
        int x = stk.size();
        while (x --) res.push_back('1');
        k --;
    }

    if (k > 0) {
        if (k & 1) res[res.size() - 1] = '0';
    }

    for (auto s : res) cout << s;
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}