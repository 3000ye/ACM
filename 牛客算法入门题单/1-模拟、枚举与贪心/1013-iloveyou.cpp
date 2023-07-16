#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int mod = 20010905;
int ls[10];

void solve() {
    string s; cin >> s;

    for (auto i : s) {
        if (i == 'i' or i == 'I') ls[0] = (ls[0] + 1) % mod;
        if (i == 'l' or i == 'L') ls[1] = (ls[1] + ls[0]) % mod;
        if (i == 'o' or i == 'O') ls[2] = (ls[2] + ls[1]) % mod;
        if (i == 'v' or i == 'V') ls[3] = (ls[3] + ls[2]) % mod;
        if (i == 'e' or i == 'E') ls[4] = (ls[4] + ls[3]) % mod;
        if (i == 'y' or i == 'Y') ls[5] = (ls[5] + ls[4]) % mod;
        if (i == 'o' or i == 'O') ls[6] = (ls[6] + ls[5]) % mod;
        if (i == 'u' or i == 'U') ls[7] = (ls[7] + ls[6]) % mod;
    }

    cout << ls[7] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}