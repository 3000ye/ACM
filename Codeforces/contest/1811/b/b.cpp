// Author: CastorYe
// Time: 2023-09-05 13:12:16
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int func(int n, int x, int y) {
    // 计算坐标在第几环
    int k = n / 2;
    
    // 分为四个区域来计算
    if (x <= k and y <= k) return min(x, y);
    else if (x <= k and y > k) return min(x, n - y + 1);
    else if (x > k and y <= k) return min(n - x + 1, y);
    else return min(n - x + 1, n - y + 1);
}

void solve() {
    int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;

    cout << abs(func(n, x1, y1) - func(n, x2, y2)) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
