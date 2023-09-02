#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

void func(int ls[N], int l, int r, int k) {
    // 右边界：左边全部数字 < k，右边全部数字 >= k
    int i = l, j = r;
    while (i + 1 != j) {  // 注意终止条件为 i, j 不相邻
        int mid = (i + j) >> 1;
        if (ls[mid] < k) i = mid;
        else j = mid;
    }

    // 判断数列 ls 中数 k 是否存在
    if (ls[j] != k) {  // 不存在则直接终止
        cout << "-1 -1" << endl;
        return;
    }
    else cout << j << " ";  // 存在则输出右边界

    // 左边界：左边全部数字 <= k，右边全部数字 > k
    i = l, j = r;
    while (i + 1 != j) {  // 注意终止条件为 i, j 不相邻
        int mid = (i + j) >> 1;
        if (ls[mid] <= k) i = mid;
        else j = mid;
    }

    cout << i << endl;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    while (q -- ) {
        int k; cin >> k;

        // l = -1, r = n;
        func(ls, -1, n, k);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}