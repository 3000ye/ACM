#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> A(n), B(n);
    for (auto &c : A) cin >> c;
    for (auto &c : B) cin >> c;

    for (int s = 0; s < n; s ++) {
        for (int t = 0; t < m; t ++) {
            bool flag = true;

            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    if (A[(i - s + n) % n][(j - t + m) % m] != B[i][j]) {
                        flag = false; break;
                    }
                }
            }

            if (flag) {cout << "Yes" << endl; return;}
        }
    }

    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}