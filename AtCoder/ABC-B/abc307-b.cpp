#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(string a, string b) {
    string x = a + b, y = a + b;
    reverse(y.begin(), y.end());

    return x == y;
}

void solve() {
    int n; cin >> n;
    vector<string> ls(n);

    for (int i = 0; i < n; i ++) cin >> ls[i];
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (check(ls[i], ls[j]) or check(ls[j], ls[i])) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}