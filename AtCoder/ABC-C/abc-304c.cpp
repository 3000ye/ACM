#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    int idx;
    int x, y;
} people;

void solve() {
    int n, d; cin >> n >> d;
    vector<bool> flag(n + 1);
    vector<people> ls(n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> ls[i].x >> ls[i].y;
        ls[i].idx = i;
    }

    // 初始化栈
    stack<people> stk;
    stk.push(ls[1]); flag[1] = true;
    while (!stk.empty()) {
        people p = stk.top(); stk.pop();

        for (int i = 1; i <= n; i ++) {
            if (p.idx != ls[i].idx and !flag[ls[i].idx]) {
                int dis = (p.x - ls[i].x) * (p.x - ls[i].x) + (p.y - ls[i].y) * (p.y - ls[i].y);

                if (dis <= d * d) {
                    flag[ls[i].idx] = true;
                    stk.push(ls[i]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (flag[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}