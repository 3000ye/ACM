# AtCoder ABC-C

## [ABC-318C](https://atcoder.jp/contests/abc318/tasks/abc318_c)

### 题面翻译

你有一个 $N$ 天的旅行计划，每一天你可以选择移动或者休息。

其中，每天移动所需费用已知。休息时需要购买套餐，一个套餐可以休息 $D$ 天，费用为 $P$ 元。

现在，请你进行合理规划，尽可能地少花钱，并输出最少花费。

### 题解（解题时间：`25:30`）

由题，我们可以利用休息套餐选择尽可能多休息，只有当休息的费用高于路费时才移动。

```cpp
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
    // ans记录总费用，sum记录路费，temp记录天数
    ll ans = 0, sum = 0, temp = 0;

    for (auto i : ls) {
        temp ++; sum += i;
		// 每隔 d 天判断一次是否休息
        if (temp == d) {
            if (sum > p) ans += p;
            else ans += sum;
            // 判断完成后清零路费和天数
            temp = 0, sum = 0;
        }
    }
    // 最终剩余天数可能不足一个套餐
    // 但我们还是需要判断一下，有可能买套餐更省
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
```

## [*ABC-317C](https://atcoder.jp/contests/abc317/tasks/abc317_c)

### 题面翻译

有 $N$ 个小镇，$M$ 条路，每条路长 $C_i$，请你找出一条没有重复小镇的最长路径。

### 题解

用二维数组存下地图，然后`dfs`暴搜。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
int dic[11][11];
int used[11], ans;

void dfs(int v, int sum) {
    ans = max(ans, sum);

    used[v] = 1;
    for (int i = 1; i <= n; i ++) {
        if (!used[i] and dic[v][i]) dfs(i, sum + dic[v][i]);
    }
    // 恢复现场
    used[v] = 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b, c; cin >> a >> b >> c;

        dic[a][b] = dic[b][a] = c;
    }

    for (int i = 1; i <= n; i ++) dfs(i, 0);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [*ABC-315C](https://atcoder.jp/contests/abc315/tasks/abc315_c)

### 题面翻译

有 $N$ 个冰淇淋，每个冰淇淋可以增加 $F_i$ 享受和 $S_i$ 美味。现在请你选择两个冰淇淋：

- 两个冰淇淋的 $S_i$ 从大到小为 $s, t$。
- 如果 $F_s == F_t$，则最终美味值为 $s + t / 2$，否则为 $s + t$。

请你求出最大美味值。

### 题解

这道题比较考验思维，我们使用`map<int, vector<int>> dic`来存储每个`F`值所包含的冰淇淋的美味度`S`，其中`dic[f]`按降序排列。

如果`dic[f]`的长度大于等于`2`，则记录一次`dic[f][0] + dic[f][1] / 2`

如果`dic[f]`的长度大于等于`1`，则将最大值`dic[f][0]`添加到一个新序列`vector<int> best`

最终，如果`best.size() >= 2`，则再记录`best[0] + best[1]`，然后返回最大值即可。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(int a, int b) {return a > b;}

void solve() {
    int n; cin >> n;
    map<int, vector<int>> dic;

    for (int i = 0; i < n; i ++) {
        int f, s; cin >> f >> s;
        dic[f].push_back(s);
    }

    int res = 0;
    vector<int> best;
    for (auto [k, v] : dic) {
        sort(v.begin(), v.end(), cmp);

        if (v.size() >= 2) res = max(res, v[0] + v[1] / 2);
        if (v.size() >= 1) best.push_back(v[0]);
    }

    sort(best.begin(), best.end(), cmp);
    if (best.size() >= 2) res = max(res, best[0] + best[1]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-314C](https://atcoder.jp/contests/abc314/tasks/abc314_c)

### 题面翻译

有一个长度为 $N$ 的字符串 $s$，其中每个字符都有一个对应的颜色 $c$。

现在，请你将 $s$ 中相同颜色的字符向前循环一步，并输出 $s$。

### 题解（解题时间：`28:17`）

使用`vector<vector<int>>`来存储每种颜色所包含的字符的索引。

然后依照索引得到相同颜色的字符序列`temp`，循环`temp`，然后按照原索引修改`s`。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    string s;
    vector<vector<int>> ls(m + 1);
    
    cin >> s;
    for (int i = 0; i < n; i ++) {
        int c; cin >> c;
        ls[c].push_back(i);
    }

    for (int i = 1; i <= m; i ++) {
        vector<char> temp;
        for (auto c : ls[i]) temp.push_back(s[c]);
        char p = temp.back(); temp.pop_back();
        reverse(temp.begin(), temp.end());
        temp.push_back(p);
        reverse(temp.begin(), temp.end());

        for (int j = 0; j < temp.size(); j ++) {
            s[ls[i][j]] = temp[j];
        }
    }

    cout << s << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-313C](https://atcoder.jp/contests/abc313/tasks/abc313_c)

### 题面翻译

有一个长度为 $N$ 的整数序列`A`，每次操作可以使 $A_i = A_i - 1, A_j = A_j + 1$。

请问至少需要多少次操作才能使序列中最小值和最大值至多相差`1`？

### 题解（解题时间：`9:30`）

由题意知，最终序列中最多只有两个不同的数。

因此，我们先求出序列和`sum`，然后分别求出`x = sum / n, y = sum % n`。即：序列最终有`y`个`x + 1`，`n - y`个`x`。

为实现最小操作数，我们将原序列按升序排列，前面的数与`x`做比较，后面的数与`x + 1`做比较，得到操作总数为`res`，由于操作时是一上一下，所以答案为`res / 2`。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> ls(n);

    ll sum = 0;
    for (auto &x : ls) {cin >> x; sum += x;}

    ll x = sum / n, y = sum % n;
    // 有 y 个 x + 1, n - y 个 x
    sort(ls.begin(), ls.end());
    ll res = 0, idx = 0;
    for (auto i : ls) {
        idx ++;
        if (idx <= n - y) res += abs(i - x);
        else res += abs(i - x - 1);
    }

    cout << res / 2 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## ABC-312C

### 题面翻译

有 $N$ 的卖家和 $M$ 个买家，卖家的价格必须大于等于要价，买家的价格必须小于等于预算。

现在请你找出最小的价格，使得卖家的人数大于等于买家的人数。

### 题解

二分查找：

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
vector<int> A, B;

bool check(int mid) {
    int sell = 0, buy = 0;
    for (int i = 0; i < n; i ++) {
        if (A[i] <= mid) sell ++;
    }
    for (int i = 0; i < m; i ++) {
        if (B[i] >= mid) buy ++;
    }

    return sell >= buy;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x; A.push_back(x);
    }
    for (int i = 0; i < m; i ++) {
        int x; cin >> x; B.push_back(x);
    }

    int l = 1, r = 1e9 + 10;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-310C](https://atcoder.jp/contests/abc310/tasks/abc310_c)

### 题面翻译

给出 $N$ 个字符串，其中两个字符串相等的条件为：两个字符串相同或一个字符串与另一个字符串的反转相同。

请求出有多少个不同的字符串。

### 题解（解题时间：`7:26`）

用`hash`存储即可，遍历字符串，如果`hash`中不存在字符串和字符串反转则`res ++`。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;

    unordered_map<string, int> dic;
    int res = 0;
    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        string t = s;
        reverse(t.begin(), t.end());

        if (dic[s] == 0 and dic[t] == 0) res ++;

        dic[s] ++; dic[t] ++;
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

## [*ABC-309C](https://atcoder.jp/contests/abc309/tasks/abc309_c)

### 题面翻译

病人有一个 $N$ 天的吃药安排：从第 $1$ 天到 $a_i$ 天，需要吃 $b_i$ 片药。

现在请你判断病人哪天吃的药的总数小于等于 $k$。

### 题解

可以看出，病人需要吃的药的数量是逐渐减少的。

因此，我们对`vector<day(a, b)>`按`a`降序排列，反向查找`> k`的`a`，如果找到则`+ 1`输出，否则说明每天吃的药都小于等于`k`，直接输出`1`。

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    ll a, b;
} day;

bool cmp(day x, day y) {
    return x.a > y.a;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<day> ls(n);
    for (auto &day : ls) cin >> day.a >> day.b;

    sort(ls.begin(), ls.end(), cmp);

    ll res = 0;
    for (auto day : ls) {
        res += day.b;

        if (res > k) {
            cout << day.a + 1 << endl;
            return;
        }
    }

    cout << 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-308C](https://atcoder.jp/contests/abc308/tasks/abc308_c)

### 题面翻译

有 $N$ 个人抛硬币，每个人抛到 $A_i$ 次正面，$B_i$ 次反面。

定义抛硬币的价值为：$\displaystyle \frac{A_i}{A_i + B_i}$

请你按照价值从大到小排序，如果存在相同值则按下标上升排序。

### 题解

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct {
    int idx;
    ld success;
} person;

bool cmp(person x, person y) {
    if (x.success == y.success) return x.idx < y.idx;
    else return x.success > y.success;
}

void solve() {
    int n; cin >> n;
    vector<person> ls;
    for (int i = 1; i <= n; i ++) {
        ld a, b; cin >> a >> b;

        ls.push_back(
            {i, a / (a + b)}
        );
    }

    sort(ls.begin(), ls.end(), cmp);
    for (auto p : ls) {
        cout << p.idx << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-307C](https://atcoder.jp/contests/abc307/tasks/abc307_c)

## ABC-306C

### 题解

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    unordered_map<int, vector<int>> dic;

    for (int i = 1; i <= 3 * n; i ++) {
        int k; cin >> k;
        dic[k].push_back(i);
    }

    vector<pair<int, int>> ls;
    for (int i = 1; i <= n; i ++) {
        sort(dic[i].begin(), dic[i].end());
        ls.push_back({i, dic[i][1]});
    }

    sort(ls.begin(), ls.end(), cmp);
    for (auto i : ls) cout << i.first << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
```

## [ABC-305C](https://atcoder.jp/contests/abc305/tasks/abc305_c)

### 题解

```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char dic[550][550];
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> dic[i][j];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (dic[i][j] == '.') {
                int temp = 0;

                for (int k = 0; k < 4; k ++) {
                    int x = i + mx[k], y = j + my[k];

                    if (dic[x][y] == '#') temp ++;
                }
                if (temp >= 2) {
                    cout << i << " " << j << endl;
                    return;
                }
            }
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

## [ABC-304C](https://atcoder.jp/contests/abc304/tasks/abc304_c)

### 题解（栈）

```cpp
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
```

## [ABC-303C](https://atcoder.jp/contests/abc303/tasks/abc303_c)

## [ABC-302C](https://atcoder.jp/contests/abc302/tasks/abc302_c)

