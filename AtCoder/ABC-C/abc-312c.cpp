#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
vector<int> A, B;

bool check(int mid) {
    int sell = 0, buy = 0;
    for (int i = 0; i < n; i ++) {
        if (A[i] <= mid) sell ++;
    }
    for (int i = 0; i < m; i ++) {
        if (B[i] >= mid) buy ++;
    }

    return sell >= buy;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x; A.push_back(x);
    }
    for (int i = 0; i < m; i ++) {
        int x; cin >> x; B.push_back(x);
    }

    int l = 1, r = 1e9 + 10;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}