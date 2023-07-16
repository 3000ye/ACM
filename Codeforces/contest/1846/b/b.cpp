#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

char dic[10][10];

bool check(char dic[10][10], char s) {
    for (int i = 1; i < 4; i ++) {
        int temp = 1;

        for (int j = 1; j < 4; j ++) {
            if (dic[i][j] != s) {temp = 0; break;}
        }

        if (temp) return 1;
    }

    for (int i = 1; i < 4; i ++) {
        int temp = 1;

        for (int j = 1; j < 4; j ++) {
            if (dic[j][i] != s) {temp = 0; break;}
        }

        if (temp) return 1;
    }

    if (dic[1][1] == s and dic[2][2] == s and dic[3][3] == s) return 1;
    if (dic[1][3] == s and dic[2][2] == s and dic[3][1] == s) return 1;

    return 0;
}

void solve() {
    for (int i = 1; i < 4; i ++) {
        for (int j = 1; j < 4; j ++) cin >> dic[i][j];
    }

    if (check(dic, 'X')) cout << "X" << endl;
    else if (check(dic, 'O')) cout << "O" << endl;
    else if (check(dic, '+')) cout << "+" << endl;
    else cout << "DRAW" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
