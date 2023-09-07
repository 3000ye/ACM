#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls(n);

    for (int i = 0; i < n; i ++) cin >> ls[i];
    for (int i = 0; i < n - 1; i ++) {
        cout << ls[i] << " ";
        if (abs(ls[i] - ls[i + 1]) != 1) {
            if (ls[i] < ls[i + 1]) {
                for (int j = ls[i] + 1; j < ls[i + 1]; j ++) {
                    cout << j << " ";
                }
            }
            else {
                for (int j = ls[i] - 1; j > ls[i + 1]; j --) {
                    cout << j << " ";
                }
            }
        }
    }
    cout << ls[n - 1] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}