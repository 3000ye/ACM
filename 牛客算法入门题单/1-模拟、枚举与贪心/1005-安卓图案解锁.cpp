#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int mp[20][20];

void solve() {
    mp[1][3] = 2, mp[1][7] = 4, mp[1][9] = 5;
    mp[2][8] = 5;
    mp[3][9] = 6, mp[3][1] = 2, mp[3][7] = 5;
    mp[4][6] = 5;
    mp[6][4] = 5;
    mp[7][1] = 4, mp[7][3] = 5, mp[7][9] = 8;
    mp[8][2] = 5;
    mp[9][1] = 5, mp[9][3] = 6, mp[9][7] = 8;

    string ls;
    while (cin >> ls) {
        int flag = 1;
        map<int, int> dic;
        dic[0] = 1;

        for (int i = 0, l = ls.size(); i < l; i ++) {
            int x = ls[i] - '0';

            if (dic[x] == 1) {flag = 0; break;}
            else {
                dic[x] = 1;
                if (i <= l - 2) {
                    int y = ls[i + 1] - '0';
                    if (dic[mp[x][y]] != 1) {flag = 0; break;}
                }
            }
        }

        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}