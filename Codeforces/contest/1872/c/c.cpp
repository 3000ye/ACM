// Author: CastorYe
// Time: 2023-09-08 15:57:12
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e7 + 10;

int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int l, r; cin >> l >> r;
    
    for (int i = l; i <= r; i ++) {
        if (!st[i]) continue;
        else {
            for (int j = 2; j < i; j ++) {
                if (__gcd(j, i - j) != 1) {
                    cout << j << " " << i - j << endl;
                    return;
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    get_primes(1e7 + 1);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
