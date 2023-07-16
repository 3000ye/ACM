#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int ls[N], res[N];

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}

ll merge_sort(int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) >> 1;
    ll ans = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int idx = 0, i = l, j = mid + 1;
    while (i <= mid and j <= r) {
        if (ls[i] <= ls[j]) res[idx ++] = ls[i ++];
        else {
            res[idx ++] = ls[j ++];
            ans += mid - i + 1;
        }
    }

    while (i <= mid) res[idx ++] = ls[i ++];
    while (j <= r) res[idx ++] = ls[j ++];

    for (int p = l, q = 0; p <= r; p ++, q ++) ls[p] = res[q];

    return ans;
}

void solve() {
    int n = read();
    for (int i = 0; i < n; i ++) ls[i] = read();

    ll ans = merge_sort(0, n - 1);
    ans %= 2;

    int m = read();
    while (m -- ) {
        int l = read();
        int r = read();
        ll mm = (r - l + 1) / 2;

        if (mm % 2 != 0) ans ^= 1;
        if (ans) cout << "dislike" << endl;
        else cout << "like" << endl;
    } 
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}