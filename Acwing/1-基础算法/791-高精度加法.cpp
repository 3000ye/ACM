#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<int> HighPrecisionNum;

HighPrecisionNum add(HighPrecisionNum &A, HighPrecisionNum &B) {
    // 大数在前
    if (A.size() < B.size()) return add(B, A);

    HighPrecisionNum C;
    int t = 0;  // 余数
    for (int i = 0; i < A.size(); i ++) {
        t += A[i];  // 余数加 A 的位数
        if (i < B.size()) t += B[i];  // 加上 B 的位数（并不总是存在）
        C.push_back(t % 10);  // 添加 C 的位数
        t /= 10;  // 余数继续保留
    }

    if (t) C.push_back(t);  // 最终余数不为 0 则也进位
    return C;
}

void solve() {
    string a, b; cin >> a >> b;
    HighPrecisionNum A, B;

    // 倒着存方便处理进位
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    HighPrecisionNum C = add(A, B);
    // 消除前导 0
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