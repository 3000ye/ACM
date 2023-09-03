#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

stack<int> ls; stack<char> op;

void eval() {
    auto b = ls.top(); ls.pop();
    auto a = ls.top(); ls.pop();
    auto c = op.top(); op.pop();

    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    ls.push(x);
}

void solve() {
    string s; cin >> s;
    unordered_map<char, int> pr{
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };

    for (int i = 0; i < s.size(); i ++) {
        auto c = s[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < s.size() and isdigit(s[j])) {
                x = x * 10 + s[j ++] - '0';
            }
            i = j - 1;
            ls.push(x);
        }
        else if (c == '(') op.push(c);
        else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        }
        else {
            while (op.size() and op.top() != '(' and pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }

    while (op.size()) eval();
    cout << ls.top() << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}