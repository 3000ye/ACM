ls = input()

x = ls.count("4") + ls.count("7")
s = str(x).replace("4", "").replace("7", "")

if s:
    print("NO")
else:
    print("YES")