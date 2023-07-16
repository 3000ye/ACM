#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool is_huiwen(string ls) {
    string temp = ls;
    reverse(temp.begin(), temp.end());

    return temp == ls;
}

string add(int n, string ls) {
    string ls_r = ls;
    reverse(ls_r.begin(), ls_r.end());

    if (n == 16) {
        map<char, int> dic;
        for (int i = 0; i < 10; i ++) dic[(char)('0' + i)] = i;
        dic['A'] = 10, dic['B'] = 11, dic['C'] = 12, dic['D'] = 13, dic['E'] = 14, dic['F'] = 15;

        map<int, char> res;
        for (int i = 0; i < 10; i ++) res[i] = (char)('0' + i);
        res[10] = 'A', res[11] = 'B', res[12] = 'C', res[13] = 'D', res[14] = 'E', res[15] = 'F';

        string temp;

        int step = 0;
        for (int i = 0; ls[i]; i ++) {
            int sum = dic[ls[i]] + dic[ls_r[i]];
            int x = (sum + step) / 16, y = (sum + step) % 16;
            step = x;

            temp += res[y];
        }
        if (step) temp += res[step];
        reverse(temp.begin(), temp.end());

        return temp;
    }
    else {
        map<char, int> dic; map<int, char> res;
        for (int i = 0; i < n; i ++) dic[(char)('0' + i)] = i, res[i] = (char)('0' + i);

        string temp;

        int step = 0;
        for (int i = 0; ls[i]; i ++) {
            int sum = dic[ls[i]] + dic[ls_r[i]];
            int x = (sum + step) / n, y = (sum + step) % n;
            step = x;

            temp += res[y];
        }
        if (step) temp += res[step];
        reverse(temp.begin(), temp.end());

        return temp;
    }
}

void solve() {
    int n; string ls;
    cin >> n >> ls;

    for (int i = 0; i < 30; i ++) {
        ls = add(n, ls);

        if (is_huiwen(ls)) {
            cout << "STEP=" << i + 1 << endl;
            return;
        }
    }

    cout << "Impossible!" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}