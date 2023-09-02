#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<int> HighPrecisionNum;

bool cmp(HighPrecisionNum &A, HighPrecisionNum &B) {
    // 判断两数的大小
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i --) {
        if (A[i] != B[i]) return A[i] > B[i];
    }

    return true;
}

HighPrecisionNum sub(HighPrecisionNum &A, HighPrecisionNum &B) {
    HighPrecisionNum C;
    for (int i = 0, t = 0; i < A.size(); i ++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);  // 保证C中的全是正数
        if (t < 0) t = 1;  // 如果 t < 0 则说明此处需要借位
        else t = 0;  // 反之不需要借位
    }

    return C;
}

void solve() {
    string a, b; cin >> a >> b;
    HighPrecisionNum A, B;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    HighPrecisionNum C;
    // 首先比较两数大小，如果是小数减大数则需要添加负号
    if (cmp(A, B)) C = sub(A, B);
    else {
        cout << "-";
        C = sub(B, A);
    }

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