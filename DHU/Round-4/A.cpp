#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 510;
int ls[N], res[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> ls[i], res[i] = ls[i];

    sort(res, res + n);

    int flag = 0;
    for (int i = 0; i < n; i ++) {
        if (res[i] != ls[i]) {  // 如果一个小数没有在前面，则寻找这个小数
            int idx = 0;
            while (ls[idx] != res[i]) idx ++;

            for (int j = 0; j < i; j ++) cout << ls[j] << " ";
            for (int j = idx; j >= i; j --) cout << ls[j] << " ";
            for (int j = idx + 1; j < n; j ++) cout << ls[j] << " ";
            cout << endl;
            flag = 1; break;
        }
    }

    if (!flag) {
        for (int i = 0; i < n; i ++) cout << ls[i] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}