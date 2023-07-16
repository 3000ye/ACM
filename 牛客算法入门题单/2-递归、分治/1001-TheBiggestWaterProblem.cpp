#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;

int func(string ls) {
    int res = 0;

    for (auto i : ls) {
        res += i - '0';
    }

    if (res < 10) return res;
    else return func(to_string(res));
}

void solve() {
    string ls; cin >> ls;

    cout << func(ls) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}