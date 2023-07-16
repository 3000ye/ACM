#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    int res = 0, flag = 0;
    int temp = 0;
    for (int i = 0; i < n; i ++) {
        int k; cin >> k;

        if (k == 0) {
            if (flag) temp ++;
            else {
                res = max(res, temp);
                temp = 1;
                flag = 1;
            }
        }
        else {
            res = max(res, temp);
            temp = 0; 
            flag = 0;
        }
    }

    res = max(res, temp);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}

