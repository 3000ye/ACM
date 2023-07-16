#include <bits/stdc++.h>
#include <bits/types/clock_t.h>
#include <ctime>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    
    clock_t c, d;
    c = clock();
    int y = 3;
    for (int i = 0; i < 100000000; i ++) y = (y * 5) >> 1;
    d = clock();
    cout << d - c << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}