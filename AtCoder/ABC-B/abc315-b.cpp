#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int ls[N];

void solve() {
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> ls[i]; sum += ls[i];
    }

    int mid = (sum + 1) / 2;
    for (int i = 0; i < n; i ++) {
        if (mid <= ls[i]) {cout << i + 1 << " " << mid << endl; return;}
        mid -= ls[i];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}