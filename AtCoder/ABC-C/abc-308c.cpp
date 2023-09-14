#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    int idx;
    ld success;
} person;

bool cmp(person x, person y) {
    if (x.success == y.success) return x.idx < y.idx;
    else return x.success > y.success;
}

void solve() {
    int n; cin >> n;
    vector<person> ls;
    for (int i = 1; i <= n; i ++) {
        ld a, b; cin >> a >> b;

        ls.push_back(
            {i, a / (a + b)}
        );
    }

    sort(ls.begin(), ls.end(), cmp);
    for (auto p : ls) {
        cout << p.idx << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}