#include<bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 2e5 + 10;

int n;
int p[N], pos;
int ne[N];
vector<int> v;

struct Edge
{
	int u, v;
}e[N];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int v;
		cin >> v;
		e[i] = {i, v};
		ne[i] = v;
	}
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 1; i <= n; i++) {
		auto[u, v] = e[i];
		int fu = find(u), fv = find(v);
		if(fu != fv) {
			p[fv] = fu;
		} else {
			pos = v;
			break;
		}
	}
	int fir = pos;
	v.push_back(pos);
	pos = ne[pos];
	for(int i = pos; i != fir; i = ne[i]) v.push_back(i);
	cout << v.size() << endl;
	for(int x : v) cout << x << ' ';
	return 0;	
}