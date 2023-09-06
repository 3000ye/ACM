#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int ls[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    sort(ls, ls + n);

    for (int i = 1; i < n; i ++) {
        if (ls[i] - ls[i - 1] != 1) {
            cout << ls[i] - 1 << endl;
            return ;
        }
    }

    cout << ls[n - 1] + 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}