#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int stk[N], idx;

void initStack() {
    idx = -1;  // 空栈
}

bool isEmpty() {
    return idx == -1;
}

void Push(int x) {
    stk[++idx] = x;
}

void Pop() {
    idx --;
}

int Query() {
    return stk[idx];
}

void solve() {
    int m; cin >> m;
    initStack();

    while (m -- ) {
        string op; cin >> op;

        if (op == "push") {
            int x; cin >> x;
            Push(x);
        }
        else if (op == "query") {
            cout << Query() << endl;
        }
        else if (op == "pop") Pop();
        else {
            isEmpty() ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}