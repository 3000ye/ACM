#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<int> HighPrecisionNum;

HighPrecisionNum mul(HighPrecisionNum &A, int b) {
    HighPrecisionNum C;

    int t = 0;
    for (int i = 0; i < A.size() or t; i ++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

void solve() {
    string a; int b; cin >> a >> b;
    HighPrecisionNum A;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    HighPrecisionNum C = mul(A, b);
    while (C.size() > 1 and C.back() == 0) C.pop_back();
    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}