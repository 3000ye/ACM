#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int dic[N][N];

void solve() {
    int n; cin >> n;

    while (n -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        for (int i = a; i < b; i ++) {
            for (int j = c; j < d; j ++) dic[i][j] = 1;
        }
    }

    int res = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            res += dic[i][j];
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}