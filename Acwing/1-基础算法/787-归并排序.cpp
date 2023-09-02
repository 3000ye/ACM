#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N], temp[N];

ll merge_sort(int ls[N], int l, int r) {
    if (l >= r) return 0;

    // 取中间数
    int mid = (l + r) >> 1;
    // 递归处理子问题
    ll res = merge_sort(ls, l, mid) + merge_sort(ls, mid + 1, r);

    // 合并子问题
    int k = 0, i = l, j = mid + 1;
    while (i <= mid and j <= r) {
        if (ls[i] <= ls[j]) temp[k ++] = ls[i ++];
        else {
            temp[k ++] = ls[j ++];
            // 记录逆序对数量
            res += mid - i + 1;
        }
    }

    while (i <= mid) temp[k ++] = ls[i ++];
    while (j <= r) temp[k ++] = ls[j ++];

    for (k = 0, i = l; i <= r; k ++, i ++) ls[i] = temp[k];

    return res;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    cout << merge_sort(ls, 0, n - 1) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}