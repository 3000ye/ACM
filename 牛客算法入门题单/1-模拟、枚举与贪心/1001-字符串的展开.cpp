#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    string ls; cin >> ls;

    for (int i = 0; ls[i]; i ++) {
        if (ls[i] != '-' or i == 0 or i == ls.size() - 1) {
            cout << ls[i];
            continue;
        }

        if ((isalpha(ls[i - 1]) and isdigit(ls[i + 1])) or (isalpha(ls[i + 1]) and isdigit(ls[i - 1])) or ls[i - 1] >= ls[i + 1] or ls[i - 1] == '-' or ls[i + 1] == '-') {
            cout << ls[i];
            continue;
        }

        string temp;
        for (char c = ls[i - 1] + 1; c < ls[i + 1]; c ++) {
            for (int j = 0; j < p2; j ++) {
                if (p1 == 1) temp += c;
                else if (p1 == 2) temp += toupper(c);
                else temp += '*';
            }
        }

        if (p3 == 2) reverse(temp.begin(), temp.end());
        cout << temp;
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}