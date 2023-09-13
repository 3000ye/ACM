#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    int yellow, red;
} person;

void solve() {
    int n, q; cin >> n >> q;
    vector<person> ls(n + 1);

    while (q -- ) {
        int op, x; cin >> op >> x;

        if (op == 1) ls[x].yellow ++;
        else if (op == 2) ls[x].red ++;
        else {
            if (ls[x].yellow >= 2 or ls[x].red >= 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}