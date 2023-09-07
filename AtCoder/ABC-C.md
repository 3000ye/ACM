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

