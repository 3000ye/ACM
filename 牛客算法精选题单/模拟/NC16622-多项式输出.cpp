#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef struct {
    int a, e;
} x;

void solve() {
    int n; cin >> n;
    
    vector<x> ls;
    for (int i = 0; i <= n; i ++) {
        int k; cin >> k;

        if (k != 0) ls.push_back({k, n - i});
    }

    // 第一个
    if (ls[0].a > 0) cout << ls[0].a << "x^" << ls[0].e;
    for (int i = 1, l = ls.size(); i < l - 1; i ++) {
        if (ls[i].a != 1) {
            if (ls[i].a > 0) cout << "+";

            cout << ls[i].a << "x^" << ls[i].e;
        }
        else cout << "x^" << ls[i].e;
    }

    // 最后一个
    if (ls[ls.size() - 1].a > 0) cout << "+";
    cout << ls[ls.size() - 1].a << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}