#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
bool ls[N];

void solve() {
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < d; j ++) {
            char c; cin >> c;

            if (c == 'x') ls[j] = true;
        }
    }

    int res = 0, temp = 0;
    for (int j = 0; j < d; j ++) {
        if (!ls[j]) temp ++;
        else {
            res = max(res, temp);
            temp = 0;
        }
    }

    res = max(res, temp);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}