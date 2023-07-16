#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
	string rep="ROYG";

	for(int i = 0; i < n - 3; i ++)
		cout << rep[i % 4];
	cout << "BIV" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
