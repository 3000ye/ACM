#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<int> HighPrecisionNum;

HighPrecisionNum div(HighPrecisionNum &A, int b, int &r) {
    HighPrecisionNum C;

    r = 0;
    for (int i = A.size() - 1; i >= 0; i --) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());
    return C;
}

void solve() {
    string a; int b; cin >> a >> b;
    HighPrecisionNum A;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');

    int r;  // 余数
    HighPrecisionNum C = div(A, b, r);
    while (C.size() > 1 and C.back() == 0) C.pop_back();
    
    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl << r << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}