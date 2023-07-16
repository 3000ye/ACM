#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string ls; cin >> ls;

    ls += "111111";

    for (int i = 0; ls[i]; i ++) {
        if (ls[i] == '0' or ls[i] == '2' or ls[i] == '4' or ls[i] == '6' or ls[i] == '9') cout << ls[i];
        else if (ls[i] == 'z' and ls[i + 1] == 'e' and ls[i + 2] == 'r' and ls[i + 3] == 'o') cout << '0';
        else if (ls[i] == 't' and ls[i + 1] == 'w' and ls[i + 2] == 'o') cout << '2';
        else if (ls[i] == 'f' and ls[i + 1] == 'o' and ls[i + 2] == 'u' and ls[i + 3] == 'r') cout << '4';
        else if (ls[i] == 's' and ls[i + 1] == 'i' and ls[i + 2] == 'x') cout << '6';
        else if (ls[i] == 'n' and ls[i + 1] == 'i' and ls[i + 2] == 'n' and ls[i + 3] == 'e') cout << '9';
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T-- ) solve();
    return 0;
}