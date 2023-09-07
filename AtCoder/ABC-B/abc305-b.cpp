#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    char p, q; cin >> p >> q;

    map<char, int> dic{
        {'A', 0}, {'B', 3}, {'C', 4}, {'D', 8}, {'E', 9}, {'F', 14}, {'G', 23}
    };

    cout << abs(dic[p] - dic[q]) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}