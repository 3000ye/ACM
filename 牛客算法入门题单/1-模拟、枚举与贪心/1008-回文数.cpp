#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    map<int, int> dic;

    // 读入数据
    for (int i = 0; i < 10; i ++) {
        int k; cin >> k;
        dic[i] = k;
    }

    // 查找 0 和奇数的数字
    int odd = 0, odd_val;
    for (int i = 1; i < 10; i ++) {
        if (dic[i] & 1) {odd ++; odd_val = i;}
    }

    // 初始化输出字符串
    string ls = "";
    if (odd > 1) {cout << -1 << endl; return;}
    else if (odd == 1 and dic[0] & 1) {cout << -1 << endl; return;}
    else if (odd == 1 and !(dic[0] & 1)) {
        char s = (char)('0' + odd_val);
        ls += s;
        dic[odd_val] -= 1;
    }
    else if (odd == 0 and dic[0] & 1) {
        ls += '0';
        dic[0] -= 1;
    }

    // 制作回文串的一半
    string head = "";
    for (int i = 1; i < 10; i ++) {
        if (dic[i] > 0) {
            int k = dic[i] / 2;
            char s = (char)('0' + i);

            for (int j = 0; j < k; j ++) head += s;
        }
    }

    // 判断是否能插入 0
    if (dic[0] > 0 and head.size() == 0) {
        if (ls == "") {
            for (int j = 0; j < dic[0]; j ++) ls += '0';

            cout << ls << endl; return;
        }
        else {cout << -1 << endl; return;}
    }
    else if (dic[0] > 0 and head.size() > 0){
        int k = dic[0] / 2;
        string temp(head.begin() + 1, head.end());

        for (int j = 0; j < k; j ++) temp = '0' + temp;
        temp = head[0] + temp;
        head = temp;
    }

    ls = head + ls;
    reverse(head.begin(), head.end());
    ls += head;
    cout << ls << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}