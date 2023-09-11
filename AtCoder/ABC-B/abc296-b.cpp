#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int x, y;
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            char c; cin >> c;
            if (c == '*') {
                x = i; y = j;
            }
        }
    }

    char ls[8] = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    cout << ls[7 - y] << 8 - x << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}