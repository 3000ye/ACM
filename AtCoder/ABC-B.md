# AtCoder ABC-B

## [ABC-318B](https://atcoder.jp/contests/abc318/tasks/abc318_b)

### 题面翻译

有 $N$ 个矩形，每个矩形的边界为 $A_i, B_i, C_i, D_i$，请你求出被矩形覆盖的区域的面积。

### 题解（解题时间：`5:45`）

由于数据量较小，可以直接暴力：

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int dic[N][N];

void solve() {
    int n; cin >> n;

    while (n -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        for (int i = a; i < b; i ++) {
            for (int j = c; j < d; j ++) dic[i][j] = 1;
        }
    }

    int res = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (dic[i][j] == 1) res ++;
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-317B](https://atcoder.jp/contests/abc317/tasks/abc317_b)

### 题面翻译

一个连续的序列中，缺失了一个数，请你找到它。

### 题解（解题时间：`4:07`）

注意序列不是从`1`开始，因此直接对序列排序之后，依次寻找相邻数之差不为`1`的数。

如果没找到，则有可能是最后的或最前面的。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int ls[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) cin >> ls[i];

    sort(ls, ls + n);

    for (int i = 1; i < n; i ++) {
        if (ls[i] - ls[i - 1] != 1) {
            cout << ls[i] - 1 << endl;
            return ;
        }
    }

    cout << ls[n - 1] + 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-315B](https://atcoder.jp/contests/abc315/tasks/abc315_b)

### 题面翻译

假设一年有 $M$ 个月，每个月有 $D_i$ 天，请你求出一年中的中间天是哪月哪天。

中间天：$\displaystyle (\sum_{i = 1}^n D_i + 1) / 2$

#### 题解（解题时间：`2:07`）

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int ls[N];

void solve() {
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> ls[i]; sum += ls[i];
    }

    int mid = (sum + 1) / 2;
    for (int i = 0; i < n; i ++) {
        if (mid <= ls[i]) {cout << i + 1 << " " << mid << endl; return;}
        mid -= ls[i];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-314B](https://atcoder.jp/contests/abc314/tasks/abc314_b)

### 题面翻译

$N$ 个人玩轮盘游戏，每个人会下 $C$ 注，对应 $C$ 的不同的数字，开奖后数字 $X$ 为中奖数字。

请你返回下注中包含 $X$ 的玩家中，下注数字数量最少的玩家编号，并按上升顺序排列编号。

### 题解（解题时间：`9:50`）

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    unordered_map<int, unordered_map<int, int>> dic;

    for (int i = 0; i < n; i ++) {
        int c; cin >> c;
        while (c -- ) {
            int a; cin >> a;
            dic[i][a] = 1;
        }
    }

    int x; cin >> x;
    vector<pair<int, int>> ls;
    for (int i = 0; i < n; i ++) {
        if (dic[i][x] == 1) ls.push_back(pair<int, int> (i, dic[i].size()));
    }

    if (ls.size() == 0) {
        cout << 0 << endl; return ;
    }

    sort(ls.begin(), ls.end(), cmp);
    int res = ls[0].second;

    vector<int> ans;
    for (auto i : ls) {
        if (i.second > res) break;
        ans.push_back(i.first + 1);
    }
    
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [*ABC-313B](https://atcoder.jp/contests/abc313/tasks/abc313_b)

### 题面翻译

有 $N$ 个人参加一个比赛，现在给出 $m$ 条信息，信息格式为：$A_i, B_i$，代表 $A_i$ 比 $B_i$ 强壮。同时，这些信息可以传递。请你找出 $N$ 个人中最强壮的人，如果没有，则返回`-1`。

### 题解

我们记录每个人是否有比自己更强壮的人，并使用`cnt`来维护没有比自己更强壮的人的数量。

如果`cnt`为`1`，则说明这就是最强壮的人，否则不存在。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
int res[N];

void solve() {
    int n, m; cin >> n >> m;
    while (m -- ) {
        int a, b; cin >> a >> b;
        res[b] ++;
    }

    int cnt = 0, idx = 1;
    for (int i = 1; i <= n; i ++) {
        if (!res[i]) {
            cnt ++; idx = i;
        }
    }

    if (cnt == 1) cout << idx << endl;
    else cout << "-1" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [*ABC-312B](https://atcoder.jp/contests/abc312/tasks/abc312_b)

### 题面翻译



### 题解（解题时间：`18:37`）

这道题主要考察模拟，首先我们需要知道`TaK Code`的形式如下：

```cpp
###.?????
###.?????
###.?????
....?????
?????????
?????....
?????.###
?????.###
?????.###
```

因此，我们按`字典序`遍历`Grid(N, M)`中可作为左上角顶点的点，判断其区域是否满足形式。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
char dic[N][N];

bool check(int i, int j) {
    // 判断以 (i, j) 为左上角的 9x9 区域是否为 TaK Code

    bool flag = true;
    // top-left
    for (int p = i; p < i + 3; p ++) {
        for (int q = j; q < j + 3; q ++) {
            if (dic[p][q] != '#') flag = false;
        }
    }

    // bottom-right
    for (int p = i + 6; p < i + 9; p ++) {
        for (int q = j + 6; q < j + 9; q ++) {
            if (dic[p][q] != '#') flag = false;
        }
    }

    // top-left line
    for (int p = i; p < i + 4; p ++) {
        if (dic[p][j + 3] != '.') flag = false;
    }
    for (int q = j; q < j + 4; q ++) {
        if (dic[i + 3][q] != '.') flag = false;
    }

    // bottom-right line
    for (int p = i + 5; p < i + 9; p ++) {
        if (dic[p][j + 5] != '.') flag = false;
    }
    for (int q = j + 5; q < j + 9; q ++) {
        if (dic[i + 5][q] != '.') flag = false;
    }

    return flag;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> dic[i][j];
    }

    for (int i = 1; i <= n - 8; i ++) {
        for (int j = 1; j <= m - 8; j ++) {
            if (check(i, j)) cout << i << " " << j << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-311B](https://atcoder.jp/contests/abc311/tasks/abc311_b)

### 题面翻译

有 $N$ 个人，每个人有 $D$ 天的日程安排，其中如果 $D_i$ 天的日程为`o`则有空，为`x`则没空。

现在请你找出所有人都有空的连续最大天数。

### 题解（解题时间：`3:52`）

使用`bool`数组来记录当天是否有人没空，然后求出最大连续`false`天数。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
bool ls[N];

void solve() {
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < d; j ++) {
            char c; cin >> c;

            if (c == 'x') ls[j] = true;
        }
    }

    int res = 0, temp = 0;
    for (int j = 0; j < d; j ++) {
        if (!ls[j]) temp ++;
        else {
            res = max(res, temp);
            temp = 0;
        }
    }

    res = max(res, temp);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-310B](https://atcoder.jp/contests/abc310/tasks/abc310_b)

### 题面翻译

有 $N$ 件产品，每件产品价格 $P$，有 $C$ 个功能，每个功能有一个编号 $F_{P, C_i}$。

现在给定一件产品绝对强于另一件产品的定义：

- $P_i > P_j$，$C_j$ 中包含所有 $C_i$ 的功能。
- $P_i = P_j$，$C_j$ 中包含所有 $C_i$ 的功能，同时 $C_j$ 至少要比 $C_i$ 多一个功能。

### 题解（解题时间：`17:02`）

由于数据量较小，所以可以直接用`O(n^2)`暴力，根据定义对产品的比较进行模拟判断。

```cpp
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
```

## [ABC-309B](https://atcoder.jp/contests/abc309/tasks/abc309_b)

### 题面翻译

给出一个 $N \times M$ 的`01`矩阵，将最外面一圈顺时针旋转一个位置。

### 题解（解题时间：`18:10`）

注意：读入的时候应该用`char`，否则会将整个读入为整数。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
char dic[N][N], res[N][N];

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> dic[i][j]; res[i][j] = dic[i][j];
        }
    }

    for (int j = 2; j <= n; j ++) res[1][j] = dic[1][j - 1];
    for (int i = 2; i <= n; i ++) res[i][n] = dic[i - 1][n];
    for (int j = n - 1; j >= 1; j --) res[n][j] = dic[n][j + 1];
    for (int i = n - 1; i >= 1; i --) res[i][1] = dic[i + 1][1];

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) cout << res[i][j];
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-308B](https://atcoder.jp/contests/abc308/tasks/abc308_b)

### 题面翻译

有 $N$ 盘寿司，每盘寿司都有一个颜色 $C_i$。

总共有 $D$ 种颜色，$D_i$ 种颜色的价格为 $P_i$，若存在 $C_i$ 的颜色不属于 $D$，则其价格为 $P_0$。

现在请你计算这 $N$ 盘寿司的价格。

### 题解（解题时间：`6:29`）

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> ls(n), ls_d(m);
    unordered_map<string, int> dic;

    for (int i = 0; i < n; i ++) cin >> ls[i];
    for (int i = 0; i < m; i ++) cin >> ls_d[i];

    int p0; cin >> p0;
    for (int i = 0; i < m; i ++) {
        int p; cin >> p; dic[ls_d[i]] = p;
    }

    int sum = 0;
    for (auto i : ls) {
        if (!dic[i]) sum += p0;
        else sum += dic[i];
    }

    cout << sum << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-307B](https://atcoder.jp/contests/abc307/tasks/abc307_b)

### 题面翻译

给出 $N$ 个字符串，判断是否存在两个不同的字符串拼接起来是回文串。

### 题解（解题时间：`5:44`）

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(string a, string b) {
    string x = a + b, y = a + b;
    reverse(y.begin(), y.end());

    return x == y;
}

void solve() {
    int n; cin >> n;
    vector<string> ls(n);

    for (int i = 0; i < n; i ++) cin >> ls[i];
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (check(ls[i], ls[j]) or check(ls[j], ls[i])) {
                cout << "Yes" << endl;
                return;
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
```

## [ABC-306B](https://atcoder.jp/contests/abc306/tasks/abc306_b)

### 题解（解题时间：`5:11`）

用`Python`更加方便：

```python
ls = list(map(int, input().split()))
sum = 0
for i in range(64):
  sum += ls[i] * pow(2, i)
  
print(sum)
```

