#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;

    int a = m / 4, b = m % 4, y = 1;
    while (n -- ) {
        if (y) {
            int x = 1;
            for (int i = 0; i < a; i ++) {
                if (x) {cout << "oooo"; x = 0;}
                else {cout << "xxxx"; x = 1;}
            }

            for (int i = 0; i < b; i ++) {
                if (x) cout << "o";
                else cout << "x";
            }
            y = 0;
        }
        else {
            int x = 1;
            for (int i = 0; i < a; i ++) {
                if (x) {cout << "xxxx"; x = 0;}
                else {cout << "oooo"; x = 1;}
            }

            for (int i = 0; i < b; i ++) {
                if (x) cout << "x";
                else cout << "o";
            }
            y = 1;
        }

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