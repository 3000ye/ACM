// Author: CastorYe
// Time: 2023-09-05 16:21:17
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    int res = 0, sum = 0;  // 需要的最少笼子数，猪的数量
    int temp1 = 0, temp2 = 0;  // 临时的猪，空的笼子

    for (int i = 0; i < n; i ++) {
        int k; cin >> k;

        if (k == 1) temp1 ++;
        else {
            if (temp1 > temp2) res += temp1 - temp2;

            sum += temp1;

            // 如果 sum 为偶数，则假设有 1 只母猪，公猪需要 (sum - 1) / 2 + 1 个笼子
            // 如果 sum 为奇数，则假设有 2 只母猪，公猪需要 (sum - 2) / 2 + 1 个笼子
            int x, y;  // 公猪和母猪所需笼子数量

            if (sum & 1) x = sum / 2, y = 1;
            else x = (sum + 1) / 2, y = 1;
            
            temp1 = 0;
            temp2 = max(0, res - x - y);
        }
    }

    if (temp1 > temp2) res += temp1 - temp2;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
