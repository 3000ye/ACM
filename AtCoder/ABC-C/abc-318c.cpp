#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(ll a, ll b) {return a > b;}

void solve() {
    ll n, d, p; cin >> n >> d >> p;
    vector<ll> ls(n), res;
    for (ll i = 0; i < n; i ++) cin >> ls[i];

    // 尽可能不给路费
    sort(ls.begin(), ls.end(), cmp);
    ll ans = 0, sum = 0, temp = 0;

    for (auto i : ls) {
        temp ++; sum += i;

        if (temp == d) {
            if (sum > p) ans += p;
            else ans += sum;

            temp = 0, sum = 0;
        }
    }
    
    if (sum > p) ans += p;
    else ans += sum;
    
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}