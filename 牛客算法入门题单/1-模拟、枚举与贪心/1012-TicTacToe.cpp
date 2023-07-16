#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char dic[10][10];

bool check_A(char dic[10][10]) {
    for (int i = 1; i < 4; i ++) {
        int temp = 1;

        for (int j = 1; j < 4; j ++) {
            if (dic[i][j] != 'A') {temp = 0; break;}
        }

        if (temp) return 1;
    }

    for (int i = 1; i < 4; i ++) {
        int temp = 1;

        for (int j = 1; j < 4; j ++) {
            if (dic[j][i] != 'A') {temp = 0; break;}
        }

        if (temp) return 1;
    }

    if (dic[1][1] == 'A' and dic[2][2] == 'A' and dic[3][3] == 'A') return 1;
    if (dic[1][3] == 'A' and dic[2][2] == 'A' and dic[3][1] == 'A') return 1;

    return 0;
}

bool check_B(char dic[10][10]) {
    for (int i = 1; i < 4; i ++) {
        int temp = 1;

        for (int j = 1; j < 4; j ++) {
            if (dic[i][j] != 'B') {temp = 0; break;}
        }

        if (temp) return 1;
    }

    for (int i = 1; i < 4; i ++) {
        int temp = 1;

        for (int j = 1; j < 4; j ++) {
            if (dic[j][i] != 'B') {temp = 0; break;}
        }

        if (temp) return 1;
    }

    if (dic[1][1] == 'B' and dic[2][2] == 'B' and dic[3][3] == 'B') return 1;
    if (dic[1][3] == 'B' and dic[2][2] == 'B' and dic[3][1] == 'B') return 1;

    return 0;
}

void solve() {
    for (int i = 1; i < 4; i ++) {
        for (int j = 1; j < 4; j ++) cin >> dic[i][j];
    }

    int a = check_A(dic), b = check_B(dic);

    if (a == 1 and b == 1) cout << "invalid" << endl;
    else if (a == 1 and b != 1) cout << "Yes" << endl;
    else if (a != 1 and b == 1) cout << "No" << endl;
    else cout << "draw" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}