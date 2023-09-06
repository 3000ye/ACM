#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    int p, c;
    vector<int> son;
} product;

void solve() {
    int n, m; cin >> n >> m;
    vector<product> ls;

    for (int i = 0; i < n; i ++) {
        int p, c; cin >> p >> c;

        product pro = {p, c, vector<int> ()};
        for (int j = 0; j < c; j ++) {
            int f; cin >> f;
            pro.son.push_back(f);
        }
        ls.push_back(pro);
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i == j) continue;
            if (ls[i].p > ls[j].p) {
                // 判断是否 ls[i].son 中所有元素都在 ls[j].son 中
                bool flag = true;
                for (auto k : ls[i].son) {
                    if (!count(ls[j].son.begin(), ls[j].son.end(), k)) {
                        flag = false; break;
                    }
                }

                if (flag) {
                    // cout << ls[i].p << " " << ls[j].p << endl;
                    cout << "Yes" << endl; return;
                }
            }
            else if (ls[i].p == ls[j].p) {
                // 判断是否 ls[i].son 中所有元素都在 ls[j].son 中
                // 同时需要 ls[j].son.size() > ls[i].son.size()
                bool flag = true;
                for (auto k : ls[i].son) {
                    if (!count(ls[j].son.begin(), ls[j].son.end(), k)) {
                        flag = false; break;
                    }
                }

                if (flag and ls[j].son.size() > ls[i].son.size()) {cout << "Yes" << endl; return;}
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}