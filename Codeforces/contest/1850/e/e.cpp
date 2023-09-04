// Author: CastorYe
// Time: 2023-09-04 12:19:39
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
ll ls[N];

void solve() {
    int n; ld c; cin >> n >> c;
    ld t = 0;

    for (int i = 0; i < n; i ++) {
        cin >> ls[i];
        c -= ls[i] * ls[i], t += 4 * ls[i];
    }

    printf(
        "%.0LF\n", (sqrt(t * t + c * n * 16) - t) / 8 / n
    );
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}