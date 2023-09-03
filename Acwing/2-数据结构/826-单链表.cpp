#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
// ls 存储链表元素值，res 存储链表的 next 索引
int ls[N], res[N];
int head, idx;

void initListNode() {
    // 从数组下标0开始，头结点起始为-1(null)
    head = -1, idx = 0;
}

void headInsert(int x) {
    // 头插法，插入一个新的头结点
    ls[idx] = x; res[idx] = head;
    head = idx; idx ++;
}

void Insert(int k, int x) {
    // 按位序插入，k > 0
    ls[idx] = x; res[idx] = res[k];
    res[k] = idx; idx ++;
}

void Remove(int k) {
    res[k] = res[res[k]];
}

void solve() {
    int m; cin >> m;
    initListNode();

    while (m -- ) {
        char op; cin >> op;

        if (op == 'H') {
            int x; cin >> x;
            headInsert(x);
        }
        else if (op == 'D') {
            int k; cin >> k;
            if (k == 0) head = res[head];
            else Remove(k - 1);
        }
        else {
            int k, x; cin >> k >> x;
            Insert(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = res[i]) cout << ls[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}