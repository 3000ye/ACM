#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

string func(string ls) {
    int flag = ls.find('.');
    if (flag == -1) return ls;

    string head(ls.begin(), ls.begin() + flag);
    if (ls[flag + 1] >= '5') {
        int l = head.size();
        while (head[l - 1] == '9') {
            head[l - 1] = '0';
            l --;
        }
        head[l - 1] += 1;

        return head;
    }

    for (int i = flag + 1; ls[i]; i ++) {
        if (ls[i] >= '5') {
            string temp = "";
            
            for (int j = flag + 1; j < i - 1; j ++) {
                temp += ls[j];
            }
            temp += ls[i - 1] + 1;

            return head + "." + temp;
        }
    }

    return ls;
}

void solve() {
    int n, t; cin >> n >> t;
    string ls; cin >> ls;

    while (t -- ) {
        if (ls == func(ls)) break;
        ls = func(ls);
    }

    cout << ls << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}