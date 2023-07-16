#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5e6 + 10;
int ls[N];

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}

void solve() {
    int n = read();
    int k = read();

    for (int i = 1; i <= n; i ++) {
        ls[i] = read();
    }

    sort(ls + 1, ls + n + 1);
    cout << ls[k] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T = read();
    while (T-- ) solve();
    return 0;
}