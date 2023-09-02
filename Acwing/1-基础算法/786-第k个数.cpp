#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

int quick_sort(int ls[N], int l, int r, int k) {
    if (l >= r) return ls[l];

    int i = l - 1, j = r + 1, mid = ls[(l + r) >> 1];
    while (i < j) {
        do i ++; while (ls[i] < mid);
        do j --; while (ls[j] > mid);
        if (i < j) swap(ls[i], ls[j]);
    }

    // 判断第 k 个数在左边还是右边
    if (k <= j) return quick_sort(ls, l, j, k);
    else return quick_sort(ls, j + 1, r, k);
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    // 目的是找到第 k 个数，即下标为 k - 1
    cout << quick_sort(ls, 0, n - 1, k - 1) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}