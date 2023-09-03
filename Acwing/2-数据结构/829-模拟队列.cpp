#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
int que[N], head, tail;

void initQueue() {
    // 队列为队尾进，队头出
    head = 0, tail = -1;
}

void Push(int x) {
    que[++tail] = x;
}

void Pop() {
    head ++;
}

bool isEmpty() {
    return head - tail == 1;
}

int Query() {
    return que[head];
}

void solve() {
    int m; cin >> m;
    initQueue();

    while (m -- ) {
        string op; cin >> op;

        if (op == "push") {
            int x; cin >> x;
            Push(x);
        }
        else if (op == "pop") Pop();
        else if (op == "query") cout << Query() << endl;
        else isEmpty() ? cout << "YES" << endl : cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}