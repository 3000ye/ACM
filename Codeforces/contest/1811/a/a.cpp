#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

// 插入使字符串字典序最大
void solve() {
    int n, k; cin >> n >> k;
    string ls; cin >> ls;

    int flag = 0;
    for (auto s: ls) {
        if (k > s - '0' and !flag) {
            cout << k << s;
            flag = 1;
        }
        else cout << s;
    }

    flag ? cout << endl : cout << k << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
