#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N];

void quick_sort(int ls[N], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, mid = ls[(l + r) >> 1];
    while (i < j) {
        do i ++; while (ls[i] < mid);
        do j --; while (ls[j] > mid);
        if (i < j) swap(ls[i], ls[j]);
    }

    quick_sort(ls, l, j), quick_sort(ls, j + 1, r);
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> ls[i];
    quick_sort(ls, 0, n - 1);

    for (int i = 0; i < n; i ++) cout << ls[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}