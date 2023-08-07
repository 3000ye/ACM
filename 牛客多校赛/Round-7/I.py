T = int(input())

ls = set()

def func(s):
    if "?" in s:
        x = s.replace("?", "0", 1)
        y = s.replace("?", "1", 1)
        func(x)
        func(y)
    else:
        ls.add(s)

for _ in range(T):
    s = input()

    func(s)

mod = 998244353
print(len(ls) % mod)
