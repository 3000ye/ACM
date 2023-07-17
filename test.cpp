#include <bits/stdc++.h>
#include <bits/types/clock_t.h>
#include <ctime>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int dic[10][10];

    memset(dic, -1, sizeof(dic));
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) cout << dic[i][j];
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}